// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreJson.h"
#include "PrefixJson.h"
#include "Score.h"

using namespace std;

ScoreJson::ScoreJson(const shared_ptr<const Score> &score)
	: score(score)
{
}

ScoreJson::operator nlohmann::json() const
{
	nlohmann::json json = PrefixJson(score->prefix());
	json.merge_patch({
		{"suffixes", score->suffixes()}
	});
	return json;
}
