// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Periodic.h"
#include <iostream>
#include <asio/placeholders.hpp>

using namespace std;

Periodic::Periodic(
	asio::io_context *ioc,
	const function<void ()> &func,
	const chrono::system_clock::duration &interval
) : timer(*ioc, interval), func(func), interval(interval)
{
}

Periodic::Periodic(
	asio::io_context *ioc,
	const function<void ()> &func,
	const shared_ptr<const Options> &options,
	const string &name
) : Periodic(ioc, func, chrono::seconds(atoi(options->value(name).c_str())))
{
}

void Periodic::start()
{
	timer.async_wait(bind(&Periodic::handler, shared_from_this(), placeholders::_1));
}

void Periodic::handler(const error_code &e)
{
	if (e != asio::error::operation_aborted) {
		try {
			func();
		} catch (const exception &e) {
			cerr << "Periodic: exception: " << e.what() << endl;
		}
		timer.expires_from_now(interval);
		timer.async_wait(bind(&Periodic::handler, shared_from_this(), placeholders::_1));
	}
}
