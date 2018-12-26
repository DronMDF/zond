// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreString.h"

using namespace std;

ScoreString::ScoreString(const shared_ptr<const Score> &score)
	: score(score)
{
}

string ScoreString::value() const
{
	// @todo #118 Create string representation of score
	return "TODO";
}
