// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreJson.h"
#include "OptionInt.h"
#include "PrefixJson.h"
#include "Score.h"

using namespace std;

ScoreJson::ScoreJson(const shared_ptr<const Score> &score, const shared_ptr<const Options> &options)
	: score(score), options(options)
{
}

ScoreJson::operator nlohmann::json() const
{
	const int strength = OptionInt(options, "strength");
	const int value = score->suffixes().size();
	nlohmann::json json = PrefixJson(score->prefix());
	json.merge_patch({
		{"expired", false},
		{"strength", strength},
		{"suffixes", score->suffixes()},
		{"value", value}
	});
	return json;
}
