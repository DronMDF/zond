// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Prefix.h"
#include "Invoice.h"

class Options;

class ServerPrefix final : public Prefix {
public:
	explicit ServerPrefix(const std::shared_ptr<const Options> &options);
	std::chrono::system_clock::time_point time() const override;
	std::string host() const override;
	int port() const override;
	std::string invoice() const override;
	std::string prefix() const override;
	std::string wallet() const override;
private:
	const std::chrono::system_clock::time_point _time;
	const std::string _host;
	const int _port;
	const Invoice _invoice;
};

