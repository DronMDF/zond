// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "HttpResponse.h"

class StringHttpResponse final : public HttpResponse {
public:
	explicit StringHttpResponse(const std::string &reponse);
	virtual std::string asString() const override;
private:
	const std::string response;
};
