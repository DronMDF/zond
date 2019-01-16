// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

class Score;

class ScoreHashString final {
public:
	// @todo #170 ScoreValid should check strength on each hash level
	//  Need make ScoreStringHash ctor with intermediate data
	explicit ScoreHashString(const std::shared_ptr<const Score> &score);

	operator std::string() const;
private:
	const std::shared_ptr<const Score> score;
};
