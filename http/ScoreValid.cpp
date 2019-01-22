// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreValid.h"
#include "HashString.h"
#include "OptionInt.h"
#include "OptionSeconds.h"
#include "Prefix.h"
#include "PrefixString.h"
#include "Score.h"
#include "Strength.h"

using namespace std;

ScoreValid::ScoreValid(
	const shared_ptr<const Score> &score,
	const shared_ptr<const Options> &options
) : score(score), options(options)
{
}

ScoreValid::operator bool() const
{
	const chrono::system_clock::duration ttl = OptionSeconds(options, "score-livetime");
	if (score->prefix()->time() + ttl < chrono::system_clock::now()) {
		return false;
	}

	string base = PrefixString(score->prefix()).value();
	for (const auto &s : score->suffixes()) {
		base = HashString(base, s);
		if (Strength(base) < OptionInt(options, "strength")) {
			return false;
		}
	}
	return true;
}
