// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <functional>
#include <memory>
#include <asio/ts/internet.hpp>
#include <asio/ts/buffer.hpp>

using namespace std;

class Session : public enable_shared_from_this<Session>
{
public:
	explicit Session(asio::ip::tcp::socket socket)
		: socket(move(socket))
	{
	}

	void start()
	{
		do_read();
	}

	void do_read()
	{
		// @todo Buffer not need, but i need to read something
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

	void on_read(error_code ec, size_t bytes_transferred [[maybe_unused]])
	{
		if (ec) {
			throw runtime_error(ec.message());
		}

		const string response =
			"HTTP/1.1 404 Not Found\r\n"
			"Content-Type: text/plain\r\n"
			"Content-Length: 9"
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

	void on_write(error_code ec, size_t bytes_transferred [[maybe_unused]])
	{
		if (ec) {
			throw runtime_error(ec.message());
		}

		do_close();
	}

	void do_close()
	{
		error_code ec;
		socket.shutdown(asio::ip::tcp::socket::shutdown_send, ec);
	}

private:
	asio::ip::tcp::socket socket;
	char data[4096];
};

class Listener : enable_shared_from_this<Listener>
{
	asio::ip::tcp::acceptor acceptor;
	asio::ip::tcp::socket socket;

public:
	Listener(asio::io_context &ioc, asio::ip::tcp::endpoint endpoint)
		: acceptor(ioc), socket(ioc)
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
		if (ec) {
			throw runtime_error(ec.message());
		}

		// Create the session and run it
		make_shared<Session>(move(socket))->start();

		// Accept another connection
		do_accept();
	}
};

int main(int, char **)
{
	const auto address = asio::ip::make_address("0.0.0.0");
	const auto port = 4096;

	asio::io_context ioc;

	make_shared<Listener>(ioc, asio::ip::tcp::endpoint{address, port})->start();

	ioc.run();

	return EXIT_SUCCESS;
}
