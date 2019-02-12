// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "../http/Score.h"

class Options;

class FakeScore final : public Score {
public:
	FakeScore(int rank, const std::shared_ptr<const Options> &options);
	explicit FakeScore(int rank = 0);
	std::shared_ptr<const Prefix> prefix() const override;
	std::list<std::string> suffixes() const override;
private:
	std::shared_ptr<const Score> score;

	std::shared_ptr<const Score> make_score(
		const std::shared_ptr<const Score> &score,
		int rank
	) const;
};
