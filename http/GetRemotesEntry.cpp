// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetRemotesEntry.h"
#include <nlohmann/json.hpp>
#include "ContentResponse.h"
#include "Options.h"
#include "ScoreJson.h"
#include "Scores.h"

using namespace std;

GetRemotesEntry::GetRemotesEntry(
	const shared_ptr<const Scores> &scores,
	const shared_ptr<const Options> &options
) : scores(scores), options(options)
{
}

unique_ptr<const Response> GetRemotesEntry::process(
	const shared_ptr<const HttpRequest> &request [[gnu::unused]]
) const
{
	// @todo #92 Fill /remotes response
	nlohmann::json score = ScoreJson(scores->front(), options);
	return make_unique<ContentResponse>(
		nlohmann::json{
			{"version", options->value("version")},
			{"score", score},
			{"all", nlohmann::json::array()}
		}
	);
}
