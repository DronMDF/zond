// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Scores.h"

class StrongestScores final : public Scores {
public:
	explicit StrongestScores(const std::shared_ptr<const Scores> &scores);
	std::shared_ptr<const Score> front() const override;
	ScoreIterator begin() const override;
	ScoreIterator end() const override;
private:
	const std::shared_ptr<const Scores> scores;
};
