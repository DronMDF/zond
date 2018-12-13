// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <nlohmann/json.hpp>
#include "HttpResponse.h"

class ContentResponse final : public HttpResponse {
public:
	explicit ContentResponse(const nlohmann::json &content);

	std::string asString() const override;
private:
	const nlohmann::json content;

	std::string type() const;
	std::string body() const;
};
