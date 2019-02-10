// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

class Options;

class Invoice final {
public:
	explicit Invoice(const std::shared_ptr<const Options> &options);

	std::string prefix() const;
	std::string wallet() const;

	std::string str() const;
private:
	const std::string pfx;
	const std::string wlt;

	std::string make_prefix(const std::shared_ptr<const Options> &options) const;
};
