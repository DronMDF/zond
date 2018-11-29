// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

class HttpResponse;

class Entry {
public:
	virtual ~Entry() = default;
	virtual std::unique_ptr<const HttpResponse> process() const = 0;
};
