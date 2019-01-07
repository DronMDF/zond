// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreString.h"
#include <sstream>
#include "PrefixString.h"
#include "Score.h"

using namespace std;

ScoreString::ScoreString(const shared_ptr<const Score> &score)
	: score(score)
{
}

string ScoreString::value() const
{
	ostringstream repr;
	repr << PrefixString(score->prefix()).value();
	for (const auto &suffix : score->suffixes()) {
		repr << " " << suffix;
	}
	return repr.str();
}
