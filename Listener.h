// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <asio/ts/internet.hpp>

class Entry;

class Listener : public std::enable_shared_from_this<Listener>
{
public:
	Listener(
		asio::io_context *ioc,
		asio::ip::tcp::endpoint endpoint,
		const std::shared_ptr<const Entry> &entry
	);

	void start();
	void do_accept();
	void on_accept(std::error_code ec);
private:
	asio::ip::tcp::acceptor acceptor;
	asio::ip::tcp::socket socket;
	const std::shared_ptr<const Entry> entry;
};
