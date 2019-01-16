// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreValid.h"

using namespace std;

ScoreValid::ScoreValid(const shared_ptr<const Score> &score)
	: score(score)
{
}

ScoreValid::operator bool() const
{
	// @todo #141 Check score
	return true;
}
