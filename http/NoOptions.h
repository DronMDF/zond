// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Options.h"

class NoOptions final : public Options {
public:
	std::string value(const std::string &name) const override;
	bool enabled(const std::string &name) const override;
};
