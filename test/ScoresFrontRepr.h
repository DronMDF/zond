// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>

class Scores;

class ScoresFrontRepr final : public oout::Representation {
public:
	explicit ScoresFrontRepr(const std::shared_ptr<const Scores> &scores);
	std::string asString() const override;
private:
	const std::shared_ptr<const Scores> scores;
};
