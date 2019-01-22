// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreHashString.h"
#include "HashString.h"
#include "Score.h"
#include "Prefix.h"
#include "PrefixString.h"

using namespace std;

ScoreHashString::ScoreHashString(const shared_ptr<const Score> &score)
	: score(score)
{
}

ScoreHashString::operator string() const
{
	string base = PrefixString(score->prefix()).value();
	for (const auto &s : score->suffixes()) {
		base = HashString(base, s);
	}
	return base;
}
