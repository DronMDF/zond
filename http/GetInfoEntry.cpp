// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetInfoEntry.h"
#include <nlohmann/json.hpp>
#include "ContentResponse.h"
#include "ScoreJson.h"
#include "Scores.h"

using namespace std;

GetInfoEntry::GetInfoEntry(const shared_ptr<const Scores> &scores)
	: scores(scores)
{
}

unique_ptr<const Response> GetInfoEntry::process(
	const shared_ptr<const HttpRequest> &request [[gnu::unused]]
) const
{
	nlohmann::json score = ScoreJson(scores->front());
	return make_unique<ContentResponse>(
		nlohmann::json{
			{"score", score}
		}
	);
}
