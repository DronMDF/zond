// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <functional>
#include <iostream>
#include <memory>
#include <asio/ts/internet.hpp>
#include <asio/ts/buffer.hpp>
#include "Session.h"

using namespace std;

// @todo #15 Move Listener to separate file
class Listener : public enable_shared_from_this<Listener>
{
	asio::ip::tcp::acceptor acceptor;
	asio::ip::tcp::socket socket;

public:
	Listener(asio::io_context *ioc, asio::ip::tcp::endpoint endpoint)
		: acceptor(*ioc), socket(*ioc)
	{
		error_code ec;

		acceptor.open(endpoint.protocol(), ec);
		if (ec) {
			throw runtime_error(ec.message());
		}

		acceptor.set_option(asio::socket_base::reuse_address(true), ec);
		if (ec) {
			throw runtime_error(ec.message());
		}

		acceptor.bind(endpoint, ec);
		if (ec) {
			throw runtime_error(ec.message());
		}

		acceptor.listen(asio::socket_base::max_listen_connections, ec);
		if (ec) {
			throw runtime_error(ec.message());
		}
	}

	void start()
	{
		if (!acceptor.is_open()) {
			return;
		}
		do_accept();
	}

	void do_accept()
	{
		acceptor.async_accept(
			socket,
			bind(&Listener::on_accept, shared_from_this(), placeholders::_1)
		);
	}

	void on_accept(error_code ec)
	{
		if (!ec) {
			make_shared<Session>(move(socket))->start();
		} else {
			cerr << "Accept aborted: " << ec.message() << endl;
		}

		do_accept();
	}
};

int main(int, char **)
{
	const auto address = asio::ip::make_address("0.0.0.0");
	const auto port = 4096;

	asio::io_context ioc;

	make_shared<Listener>(&ioc, asio::ip::tcp::endpoint{address, port})->start();

	ioc.run();

	return EXIT_SUCCESS;
}
