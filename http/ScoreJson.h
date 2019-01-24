// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <nlohmann/json.hpp>

class Score;

class ScoreJson final {
public:
	explicit ScoreJson(const std::shared_ptr<const Score> &score);
	operator nlohmann::json() const;
private:
	const std::shared_ptr<const Score> score;
};
