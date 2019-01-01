// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "../http/Scores.h"

class FakeScores final : public Scores {
private:
	// Primary ctor
	explicit FakeScores(const std::shared_ptr<const ScoreIterator> &scores);
public:
	FakeScores();

	template<class ... T>
	FakeScores(const std::shared_ptr<const Score> &score, T ... args)
		: FakeScores(std::make_shared<ScoreIterator>(score, args...))
	{
	}

	std::shared_ptr<const Score> front() const override;
	ScoreIterator begin() const override;
	ScoreIterator end() const override;
private:
	std::shared_ptr<const ScoreIterator> scores;
};

