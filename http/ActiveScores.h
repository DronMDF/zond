// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Scores.h"

class Options;

class ActiveScores final : public Scores {
public:
	explicit ActiveScores(const std::shared_ptr<const Options> &options);

	std::shared_ptr<const Score> front() const override;
	ScoreIterator begin() const override;
	ScoreIterator end() const override;
private:
	const std::shared_ptr<const Options> options;
	std::shared_ptr<const Score> active;

	// @todo #136 ActiveScores need method for extent existing score with new suffixes
	// @todo #136 ActiveScores need to periodically renew, replace old score to new score
};
