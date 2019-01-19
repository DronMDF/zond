// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Prefix.h"

class StringPrefix final : public Prefix {
public:
	explicit StringPrefix(const std::string &prefix);
	std::chrono::system_clock::time_point time() const override;
	std::string host() const override;
	int port() const override;
	std::string invoice() const override;
private:
	const std::string pfx;
};
