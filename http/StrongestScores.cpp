// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StrongestScores.h"
#include "Score.h"

using namespace std;

StrongestScores::StrongestScores(const shared_ptr<const Scores> &scores)
	: scores(scores)
{
}

shared_ptr<const Score> StrongestScores::front() const
{
	shared_ptr<const Score> score;
	for (const auto &s : *scores) {
		// @todo #128 Extract ScoreStrength to another class
		if (!score || score->suffixes().size() < s->suffixes().size()) {
			score = s;
		}
	}
	return score;
}

ScoreIterator StrongestScores::begin() const
{
	return ScoreIterator(front());
}

ScoreIterator StrongestScores::end() const
{
	return {};
}
