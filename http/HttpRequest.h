// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <string>

class HttpHeader;

class HttpRequest final {
public:
	HttpRequest(const std::shared_ptr<const HttpHeader> &header, const std::string &body);

	std::string uri() const;
private:
	const std::shared_ptr<const HttpHeader> header;
	const std::string body;
};

