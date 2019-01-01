// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>

class Prefix;

class Score {
public:
	virtual ~Score() = default;
	virtual std::shared_ptr<const Prefix> prefix() const = 0;
	virtual std::list<std::string> suffixes() const = 0;
};
