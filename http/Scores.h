// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "ScoreIterator.h"

class Score;

class Scores {
public:
	virtual ~Scores() = default;
	virtual std::shared_ptr<const Score> front() const = 0;
	virtual ScoreIterator begin() const = 0;
	virtual ScoreIterator end() const = 0;
};
