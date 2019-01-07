// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

class Score;

class ScoreString final {
public:
	explicit ScoreString(const std::shared_ptr<const Score> &score);
	std::string value() const;
private:
	const std::shared_ptr<const Score> score;
};
