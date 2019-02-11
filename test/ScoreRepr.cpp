// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreRepr.h"
#include "../http/ScoreString.h"
#include "FakeOptions.h"

using namespace std;

ScoreRepr::ScoreRepr(const shared_ptr<const Score> &score)
	: score(score)
{
}

string ScoreRepr::asString() const
{
	return ScoreString(score, make_shared<FakeOptions>()).value();
}
