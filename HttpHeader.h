// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>

class HttpHeader final {
public:
	explicit HttpHeader(const std::string &header);

	std::string getField(const std::string &name, const std::string &default_value = "") const;
private:
	const std::string header;
};
