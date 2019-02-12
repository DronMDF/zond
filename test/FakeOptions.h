// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "../http/Options.h"
#include "../http/PredefinedOptions.h"

class FakeOptions final : public Options {
public:
	explicit FakeOptions(const std::shared_ptr<const Options> &options);

	template<class ... T>
	FakeOptions(const std::string &name, T ... args)
		: FakeOptions(std::make_shared<PredefinedOptions>(name, args...))
	{
	}

	FakeOptions();

	std::string value(const std::string &name) const override;
	bool enabled(const std::string &name) const override;
private:
	const std::shared_ptr<const Options> options;
};
