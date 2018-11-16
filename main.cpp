// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>

using namespace std;

// Handles an HTTP server connection
class Session : public enable_shared_from_this<Session>
{
private:
	boost::asio::ip::tcp::socket socket;
	boost::beast::flat_buffer buffer;
	boost::beast::http::request<boost::beast::http::string_body> req;
	std::shared_ptr<void> res;

public:
	// Take ownership of the socket
	explicit Session(boost::asio::ip::tcp::socket socket)
		: socket(move(socket))
	{
	}

	// Start the asynchronous operation
	void run()
	{
		do_read();
	}

	void do_read()
	{
		// Make the request empty before reading,
		// otherwise the operation behavior is undefined.
		req = {};

		// Read a request
		boost::beast::http::async_read(
			socket,
			buffer,
			req,
			bind(
				&Session::on_read,
				shared_from_this(),
				placeholders::_1,
				placeholders::_2
			)
		);
	}

	void on_read(boost::system::error_code ec, size_t bytes_transferred)
	{
		boost::ignore_unused(bytes_transferred);

		// This means they closed the connection
		if (ec == boost::beast::http::error::end_of_stream) {
			return do_close();
		}

		if (ec) {
			throw runtime_error(ec.message());
		}

		// Any request cause not found
		boost::beast::http::response<boost::beast::http::string_body> response(
			boost::beast::http::status::not_found,
			11
		);
		response.body() = "Not found";
		response.prepare_payload();

		// Write the response
		boost::beast::http::async_write(
			socket,
			response,
			bind(
				&Session::on_write,
				shared_from_this(),
				placeholders::_1,
				placeholders::_2
			)
		);
	}

	void on_write(boost::system::error_code ec, size_t bytes_transferred)
	{
		boost::ignore_unused(bytes_transferred);

		if (ec) {
			throw runtime_error(ec.message());
		}

		// We're done with the response so delete it
		res = nullptr;

		// Read another request
		do_read();
	}

	void do_close()
	{
		// Send a TCP shutdown
		boost::system::error_code ec;
		socket.shutdown(boost::asio::ip::tcp::socket::shutdown_send, ec);

		// At this point the connection is closed gracefully
	}
};

class Listener : public std::enable_shared_from_this<Listener>
{
	boost::asio::ip::tcp::acceptor acceptor;
	boost::asio::ip::tcp::socket socket;

public:
	Listener(boost::asio::io_context &ioc, boost::asio::ip::tcp::endpoint endpoint)
		: acceptor(ioc), socket(ioc)
	{
		boost::system::error_code ec;

		// Open the acceptor
		acceptor.open(endpoint.protocol(), ec);
		if (ec) {
			throw runtime_error(ec.message());
		}

		// Allow address reuse
		acceptor.set_option(boost::asio::socket_base::reuse_address(true), ec);
		if (ec) {
			throw runtime_error(ec.message());
		}

		// Bind to the server address
		acceptor.bind(endpoint, ec);
		if (ec) {
			throw runtime_error(ec.message());
		}

		// Start listening for connections
		acceptor.listen(boost::asio::socket_base::max_listen_connections, ec);
		if (ec) {
			throw runtime_error(ec.message());
		}
	}

	// Start accepting incoming connections
	void run()
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

	void on_accept(boost::system::error_code ec)
	{
		if (ec) {
			throw runtime_error(ec.message());
		}

		// Create the session and run it
		make_shared<Session>(move(socket))->run();

		// Accept another connection
		do_accept();
	}
};

int main(int, char **)
{
	const auto address = boost::asio::ip::make_address("0.0.0.0");
	const auto port = 4096;

	boost::asio::io_context ioc;

	make_shared<Listener>(ioc, boost::asio::ip::tcp::endpoint{address, port})->run();

	ioc.run();

	return EXIT_SUCCESS;
}
