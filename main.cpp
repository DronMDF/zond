// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <asio/ts/internet.hpp>
#include "Listener.h"
#include "NotFoundEntry.h"

using namespace std;

int main(int, char **)
{
	const auto address = asio::ip::make_address("0.0.0.0");
	const auto port = 4096;

	asio::io_context ioc;

	make_shared<Listener>(
		&ioc,
		asio::ip::tcp::endpoint{address, port},
		make_shared<NotFoundEntry>()
	)->start();

	// @todo #18 Create multythreaded pool of workers
	ioc.run();

	return EXIT_SUCCESS;
}
