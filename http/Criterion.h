// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

class HttpRequest;

class Criterion {
public:
	virtual ~Criterion() = default;
	virtual bool suitable(const std::shared_ptr<const HttpRequest> &request) const = 0;
};
