// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Score.h"

class Options;

class ServerScore final : public Score {
public:
	explicit ServerScore(const std::shared_ptr<const Options> &options);

	std::shared_ptr<const Prefix> prefix() const override;
	std::list<std::string> suffixes() const override;
private:
	const std::shared_ptr<const Prefix> _prefix;
};
