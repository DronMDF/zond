// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <asio/ts/internet.hpp>
#include "Listener.h"
#include "http/EqualCriterion.h"
#include "http/GetInfoEntry.h"
#include "http/GetRemotesEntry.h"
#include "http/GetVersionEntry.h"
#include "http/MethodCriterion.h"
#include "http/SelectedEntry.h"

using namespace std;

int main(int, char **)
{
	const auto address = asio::ip::make_address("0.0.0.0");
	const auto port = 4096;

	asio::io_context ioc;

	make_shared<Listener>(
		&ioc,
		asio::ip::tcp::endpoint{address, port},
		make_shared<SelectedEntry>(
			// Server statistin entry
			make_shared<MethodCriterion>(
				"GET",
				make_shared<EqualCriterion>("/")
			),
			make_shared<GetInfoEntry>(),
			// Server version entry
			make_shared<MethodCriterion>(
				"GET",
				make_shared<EqualCriterion>("/version")
			),
			make_shared<GetVersionEntry>(),
			// List of remotes entry
			make_shared<MethodCriterion>(
				"GET",
				make_shared<EqualCriterion>("/remotes")
			),
			make_shared<GetRemotesEntry>()
			// @todo #82 Add GET /wallet/xxx entry
			// @todo #83 Add GET /wallet/xxx/balance entry
			// @todo #82 Add PUT /wallet/xxx entry
		)
	)->start();

	// @todo #18 Create multythreaded pool of workers
	ioc.run();

	return EXIT_SUCCESS;
}
