// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Session.h"
#include <functional>
#include <iostream>
#include <asio/ts/buffer.hpp>
#include "HttpHeader.h"

using namespace std;

Session::Session(asio::ip::tcp::socket socket)
	: socket(move(socket)), buffer()
{
}

void Session::start()
{
	do_read_header();
}

void Session::do_read_header()
{
	// @todo #18 Need to control asio::read time
	//  Use deadline_timer for that
	asio::async_read_until(
		socket,
		buffer,
		"\r\n\r\n",
		bind(
			&Session::on_read_header,
			shared_from_this(),
			placeholders::_1,
			placeholders::_2
		)
	);
}

void Session::on_read_header(error_code ec, size_t size)
{
	if (ec) {
		cerr << "Connecton " << this << " aborted: " << ec.message() << endl;
		do_close();
		return;
	}

	const auto header = make_shared<HttpHeader>(
		string(
			asio::buffers_begin(buffer.data()),
			asio::buffers_begin(buffer.data()) + size
		)
	);
	buffer.consume(size);

	// @todo #18 Read Http body
	//  size of body keep in Content-Length header field

	const string response =
		"HTTP/1.1 404 Not Found\r\n"
		"Content-Type: text/plain\r\n"
		"Content-Length: 9\r\n"
		"\r\n"
		"Not Found";

	asio::async_write(
		socket,
		asio::buffer(response),
		bind(
			&Session::on_write,
			shared_from_this(),
			placeholders::_1,
			placeholders::_2
		)
	);
}

// @todo #15 Use maybe_unused attrib when compiler is updated to version 7
void Session::on_write(error_code ec, size_t bytes_transferred [[gnu::unused]])
{
	if (ec) {
		cerr << "Connecton " << this << " aborted: " << ec.message() << endl;
	}

	do_close();
}

void Session::do_close()
{
	error_code ec;
	socket.shutdown(asio::ip::tcp::socket::shutdown_send, ec);
}
