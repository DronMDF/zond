// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <nlohmann/json.hpp>

class Score;
class Options;

class ScoreJson final {
public:
	ScoreJson(
		const std::shared_ptr<const Score> &score,
		const std::shared_ptr<const Options> &options
	);
	operator nlohmann::json() const;
private:
	const std::shared_ptr<const Score> score;
	const std::shared_ptr<const Options> options;
};
