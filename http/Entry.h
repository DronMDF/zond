// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

class HttpRequest;
class Response;

class Entry {
public:
	virtual ~Entry() = default;
	virtual std::unique_ptr<const Response> process(
		const std::shared_ptr<const HttpRequest> &request
	) const = 0;
};
