// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "../http/Score.h"

class FakeScore final : public Score {
public:
	explicit FakeScore(size_t strength = 0);
	std::shared_ptr<const Prefix> prefix() const override;
	std::list<std::string> suffixes() const override;
private:
	const size_t strength;
};
