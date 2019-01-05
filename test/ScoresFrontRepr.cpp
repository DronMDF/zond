// Copyright (c) 2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoresFrontRepr.h"
#include "../http/Scores.h"
#include "../http/ScoreString.h"

using namespace std;

ScoresFrontRepr::ScoresFrontRepr(const shared_ptr<const Scores> &scores)
	: scores(scores)
{
}

string ScoresFrontRepr::asString() const
{
	return ScoreString(scores->front()).value();
}
