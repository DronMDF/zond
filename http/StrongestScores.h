// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Scores.h"

class StrongestScores final : public Scores {
public:
	std::shared_ptr<const Score> front() const override;
};
