// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>

class Response {
public:
	virtual ~Response() = default;
	virtual std::string asString() const = 0;
};
