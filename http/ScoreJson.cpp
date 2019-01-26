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
	nlohmann::json json = PrefixJson(score->prefix());
	// @todo #185 Score json should have 'value' field
	// @todo #185 Score json should have 'expired' field
	json.merge_patch({
		{"suffixes", score->suffixes()},
		{"strength", int(OptionInt(options, "strength"))}
	});
	return json;
}
