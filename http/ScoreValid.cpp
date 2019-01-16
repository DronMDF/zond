// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreValid.h"
#include "OptionInt.h"
#include "OptionSeconds.h"
#include "Prefix.h"
#include "Score.h"
#include "ScoreHashString.h"
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

	// @todo #170 ScoreValid check only last level of hash - this is wrong
	if (Strength(ScoreHashString(score)) < OptionInt(options, "strength")) {
		return false;
	}
	return true;
}
