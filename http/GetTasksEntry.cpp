// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetTasksEntry.h"
#include <nlohmann/json.hpp>
#include "ActiveScores.h"
#include "ContentResponse.h"
#include "ScoreString.h"

using namespace std;

GetTasksEntry::GetTasksEntry(
	const shared_ptr<const ActiveScores> &scores,
	const shared_ptr<const Options> &options
) : scores(scores), options(options)
{
}

unique_ptr<const Response> GetTasksEntry::process(
	const shared_ptr<const HttpRequest> &request [[gnu::unused]]
) const
{
	const string score = ScoreString(scores->back(), options).value();
	return make_unique<ContentResponse>(
		nlohmann::json{
			{ "tasks", {
				{
					{"type", "mining"},
					{"score", score}
				}
			}}
		}
	);
}

