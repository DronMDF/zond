// Copyright (c) 2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreIterator.h"

using namespace std;

ScoreIterator::ScoreIterator(
	const shared_ptr<const Score> &score,
	const shared_ptr<const ScoreIterator> &next
) : score(score), next(next)
{
}

ScoreIterator::ScoreIterator(const shared_ptr<const Score> &score)
	: ScoreIterator(score, {})
{
}

ScoreIterator::ScoreIterator()
	: ScoreIterator({}, {})
{
}

bool ScoreIterator::operator != (const ScoreIterator &other) const
{
	return score != other.score;
}

ScoreIterator &ScoreIterator::operator ++()
{
	if (next) {
		score = next->score;
		next = next->next;
	} else {
		score.reset();
	}
	return *this;
}

shared_ptr<const Score> ScoreIterator::operator *() const
{
	return score;
}
