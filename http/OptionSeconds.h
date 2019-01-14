// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <chrono>
#include <memory>
#include <string>

class Options;

class OptionSeconds final {
public:
	OptionSeconds(const std::shared_ptr<const Options> &options, const std::string &name);
	operator std::chrono::system_clock::duration() const;
private:
	const std::shared_ptr<const Options> options;
	const std::string name;
};
