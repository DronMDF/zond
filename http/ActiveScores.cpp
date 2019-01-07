// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ActiveScores.h"
#include "ServerScore.h"

using namespace std;

ActiveScores::ActiveScores(const shared_ptr<const Options> &options)
	: options(options), active(make_shared<ServerScore>(options))
{
}

shared_ptr<const Score> ActiveScores::front() const
{
	return active;
}

ScoreIterator ActiveScores::begin() const
{
	return ScoreIterator(active);
}

ScoreIterator ActiveScores::end() const
{
	return {};
}
