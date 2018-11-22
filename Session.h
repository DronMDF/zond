// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <asio/ts/internet.hpp>
#include <asio/streambuf.hpp>

class Session : public std::enable_shared_from_this<Session>
{
public:
	explicit Session(asio::ip::tcp::socket socket);

	void start();

	void do_read_header();
	void on_read_header(std::error_code ec, size_t bytes_transferred);

	void on_write(std::error_code ec, size_t bytes_transferred);

	void do_close();
private:
	asio::ip::tcp::socket socket;
	asio::streambuf buffer;
};
