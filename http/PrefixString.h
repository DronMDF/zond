// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

class Prefix;

class PrefixString final {
public:
	explicit PrefixString(const std::shared_ptr<const Prefix> &prefix);
	std::string value() const;
private:
	const std::shared_ptr<const Prefix> prefix;
};
