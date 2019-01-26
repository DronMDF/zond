// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetInfoEntry.h"
#include <nlohmann/json.hpp>
#include "ContentResponse.h"
#include "OptionInt.h"
#include "ScoreJson.h"
#include "Scores.h"

using namespace std;

GetInfoEntry::GetInfoEntry(
	const shared_ptr<const Scores> &scores,
	const shared_ptr<const Options> &options
) : scores(scores), options(options)
{
}

unique_ptr<const Response> GetInfoEntry::process(
	const shared_ptr<const HttpRequest> &request [[gnu::unused]]
) const
{
	nlohmann::json score = ScoreJson(scores->front(), options);
	return make_unique<ContentResponse>(
		nlohmann::json{
			{"age", 1},
			{"cpus", 0},
			{"entrance", {"queue", 0}},
			{"history", nlohmann::json::array()},
			{"load", 0},
			{"memory", 3 * 1024 * 1024},
			{"nscore", 0},
			{"platform", "null"},
			{"processes", 1},
			{"protocol", int(OptionInt(options, "protocol"))},
			// @todo #185 GetInfo should contain real remotes counts
			{"remotes", 0},
			{"score", score},
			{"speed", 0},
			{"threads", int(OptionInt(options, "mining-threads"))},
			{"total_mem", 4 * 1024 * 1024},
			// @todo #185 GetInfo should contain real wallet counts
			{"wallets", 0}
		}
	);
}
