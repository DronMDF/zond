// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include "Options.h"

class CommandlineOptions final : public Options {
public:
	explicit CommandlineOptions(const std::list<std::string> &options);
	std::string value(const std::string &name) const override;
	bool enabled(const std::string &name) const override;
private:
	const std::list<std::string> options;
};
