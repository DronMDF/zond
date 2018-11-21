// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Session.h"
#include <functional>
#include <iostream>
#include <asio/ts/buffer.hpp>

using namespace std;

Session::Session(asio::ip::tcp::socket socket)
	: socket(move(socket)), data()
{
}

void Session::start()
{
	do_read();
}

void Session::do_read()
{
	socket.async_read_some(
		asio::buffer(data, 4096),
		bind(
			&Session::on_read,
			shared_from_this(),
			placeholders::_1,
			placeholders::_2
		)
	);
}

void Session::on_read(error_code ec, size_t bytes_transferred [[gnu::unused]])
{
	if (ec) {
		cerr << "Connecton " << this << " aborted: " << ec.message() << endl;
		do_close();
		return;
	}

	// @todo #15 Parse request and handle it
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
