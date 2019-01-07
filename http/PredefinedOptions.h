// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <map>
#include <string>
#include "Options.h"

class PredefinedOptions final : public Options {
public:
	// Primary ctor
	explicit PredefinedOptions(const std::map<std::string, std::string> &options);

	template<class ... T>
	PredefinedOptions(const std::pair<std::string, std::string> &vp, T ... args)
		: PredefinedOptions(std::map<std::string, std::string>{vp, args...})
	{
	}

	template<class ... T>
	PredefinedOptions(const std::string &name, const std::string &value, T ... args)
		: PredefinedOptions(args..., make_pair(name, value))
	{
	}

	std::string value(const std::string &name) const override;
	bool enabled(const std::string &name) const override;
private:
	std::map<std::string, std::string> options;
};
