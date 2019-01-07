// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <chrono>
#include <string>

class Prefix {
public:
	virtual ~Prefix() = default;
	virtual std::chrono::system_clock::time_point time() const = 0;
	virtual std::string host() const = 0;
	virtual int port() const = 0;
	virtual std::string invoice() const = 0;
};
