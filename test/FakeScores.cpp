// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FakeScores.h"
#include "FakeScore.h"

using namespace std;

FakeScores::FakeScores(const shared_ptr<const ScoreIterator> &scores)
	: scores(scores)
{
}

FakeScores::FakeScores()
	: FakeScores(make_shared<FakeScore>())
{
}

shared_ptr<const Score> FakeScores::front() const
{
	const auto score = **scores;
	if (!score) {
		throw runtime_error("No score in FakeScores");
	}
	return score;
}

ScoreIterator FakeScores::begin() const
{
	return *scores;
}

ScoreIterator FakeScores::end() const
{
	return {};
}
