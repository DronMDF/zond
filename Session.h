// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <asio/ts/internet.hpp>
#include <asio/streambuf.hpp>

class Entry;
class HttpHeader;

class Session final : public std::enable_shared_from_this<Session> {
public:
	Session(asio::ip::tcp::socket socket, const std::shared_ptr<const Entry> &entry);

	void start();

	void do_read_header();
	void on_read_header(std::error_code ec, size_t size);
	void on_read_body(
		std::error_code ec,
		size_t size,
		const std::shared_ptr<const HttpHeader> &header
	);

	void on_write(std::error_code ec, size_t size);

	void do_close();
private:
	asio::ip::tcp::socket socket;
	asio::streambuf buffer;
	const std::shared_ptr<const Entry> entry;
};
