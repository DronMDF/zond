// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "HttpResponse.h"

class ParamResponse final : public HttpResponse {
public:
	ParamResponse(
		const std::shared_ptr<const HttpResponse> &response,
		const std::string &name,
		const std::string &value
	);
	std::string asString() const override;
private:
	const std::shared_ptr<const HttpResponse> response;
	const std::string name;
	const std::string value;
};

