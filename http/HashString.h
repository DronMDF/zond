// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>

class HashString final {
public:
	explicit HashString(const std::string &str);
	HashString(const std::string &base, const std::string &suffix);

	operator std::string() const;
private:
	const std::string str;
};
