// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>

class Options {
public:
	virtual ~Options() = default;
	virtual std::string value(const std::string &name) const = 0;
	virtual bool enabled(const std::string &name) const = 0;
};
