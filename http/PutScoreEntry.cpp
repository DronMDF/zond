// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "PutScoreEntry.h"
#include <nlohmann/json.hpp>
#include "ActiveScores.h"
#include "HttpRequest.h"
#include "ContentResponse.h"

using namespace std;

PutScoreEntry::PutScoreEntry(const shared_ptr<ActiveScores> &scores)
	: scores(scores)
{
}

unique_ptr<const Response> PutScoreEntry::process(
	const shared_ptr<const HttpRequest> &request
) const
{
	const auto body = nlohmann::json::parse(request->content());
	scores->extend(body.at("suffix"));
	return make_unique<ContentResponse>(nlohmann::json::object());
}
