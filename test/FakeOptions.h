// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "../http/Options.h"

class FakeOptions final : public Options {
public:
	// @todo #194 Customuze some options in FakeOptions
	FakeOptions();
	std::string value(const std::string &name) const override;
	bool enabled(const std::string &name) const override;
private:
	const std::shared_ptr<const Options> options;
};
