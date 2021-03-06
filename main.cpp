// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <asio/ts/internet.hpp>
#include "Listener.h"
#include "Periodic.h"
#include "http/ActiveScores.h"
#include "http/CommandlineOptions.h"
#include "http/EqualCriterion.h"
#include "http/GetInfoEntry.h"
#include "http/GetRemotesEntry.h"
#include "http/GetTasksEntry.h"
#include "http/GetVersionEntry.h"
#include "http/MethodCriterion.h"
#include "http/MiningPool.h"
#include "http/MultipleSourcesOptions.h"
#include "http/OptionInt.h"
#include "http/PredefinedOptions.h"
#include "http/PutScoreEntry.h"
#include "http/SelectedEntry.h"
#include "http/StrongestScores.h"
#include "http/ZoldProtocolEntry.h"

using namespace std;

int main(int argc, char **argv)
{
	const auto options = make_shared<MultipleSourcesOptions>(
		make_shared<CommandlineOptions>(list<string>(argv + 1, argv + argc)),
		// @todo #117 Get options from config file
		make_shared<PredefinedOptions>(
			"port", "4096",
			"listen-address", "0.0.0.0",
			"score-livetime", "86400",
			"score-miningtime", "43200",
			"mining-threads", "0",
			"mining-interval", "10",
			"server-version", "0.1.0",
			"server-repo", "dronmdf/zond",
			"prefix-length", "8",
			"protocol", "2",
			"default-network", "zold",
			"strength", "8",
			"version", "0.1.0"
			// Features
		)
	);

	const auto scores = make_shared<ActiveScores>(options);

	asio::io_context ioc;

	make_shared<Periodic>(
		&ioc,
		bind(&ActiveScores::renew, scores),
		options,
		"score-miningtime"
	)->start();

	MiningPool mining_pool(options, scores);

	const auto address = asio::ip::make_address(options->value("listen-address"));
	const in_port_t port = OptionInt(options, "port");

	make_shared<Listener>(
		&ioc,
		asio::ip::tcp::endpoint{address, port},
		make_shared<ZoldProtocolEntry>(
			make_shared<SelectedEntry>(
				// Server statistin entry
				make_shared<MethodCriterion>(
					"GET",
					make_shared<EqualCriterion>("/")
				),
				make_shared<GetInfoEntry>(
					make_shared<StrongestScores>(scores),
					options
				),
				// Server version entry
				make_shared<MethodCriterion>(
					"GET",
					make_shared<EqualCriterion>("/version")
				),
				make_shared<GetVersionEntry>(options),
				// List of remotes entry
				make_shared<MethodCriterion>(
					"GET",
					make_shared<EqualCriterion>("/remotes")
				),
				make_shared<GetRemotesEntry>(
					make_shared<StrongestScores>(scores),
					options
				),
				// External tasks
				make_shared<MethodCriterion>(
					"GET",
					make_shared<EqualCriterion>("/tasks")
				),
				make_shared<GetTasksEntry>(scores, options),
				// Post suffixes
				make_shared<MethodCriterion>(
					"PUT",
					make_shared<EqualCriterion>("/score")
				),
				make_shared<PutScoreEntry>(scores)
				// @todo #82 Add GET /wallet/xxx entry
				// @todo #83 Add GET /wallet/xxx/balance entry
				// @todo #82 Add PUT /wallet/xxx entry
			),
			make_shared<StrongestScores>(scores),
			options
		)
	)->start();

	// @todo #18 Create multythreaded pool of workers
	ioc.run();

	return EXIT_SUCCESS;
}
