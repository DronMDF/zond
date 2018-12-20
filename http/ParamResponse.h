// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Response.h"

class ParamResponse final : public Response {
public:
	ParamResponse(
		const std::shared_ptr<const Response> &response,
		const std::string &name,
		const std::string &value
	);
	std::string asString() const override;
private:
	const std::shared_ptr<const Response> response;
	const std::string name;
	const std::string value;
};

