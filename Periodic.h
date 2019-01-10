// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <chrono>
#include <functional>
#include <memory>
#include <asio/ts/internet.hpp>
#include <asio/ts/timer.hpp>

class Periodic final : public std::enable_shared_from_this<Periodic> {
public:
	Periodic(
		asio::io_context *ioc,
		const std::function<void ()> &func,
		const std::chrono::system_clock::duration &interval
	);

	void start();

private:
	asio::steady_timer timer;
	const std::function<void ()> func;
	const std::chrono::system_clock::duration interval;

	void handler(const std::error_code &e);
};
