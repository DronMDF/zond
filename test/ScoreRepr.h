// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>

class Score;

class ScoreRepr final : public oout::Representation {
public:
	explicit ScoreRepr(const std::shared_ptr<const Score> &score);
	std::string asString() const override;
private:
	const std::shared_ptr<const Score> score;
};
