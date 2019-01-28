// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Score.h"

// @todo #202 StringScore precessed invalid string without error
class StringScore final : public Score {
public:
	explicit StringScore(const std::string &score);
	std::shared_ptr<const Prefix> prefix() const override;
	std::list<std::string> suffixes() const override;
private:
	const std::string score;
};
