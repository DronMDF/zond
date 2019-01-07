// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Response.h"

class ParamResponse final : public Response {
public:
	// Primary ctor
	ParamResponse(
		const std::shared_ptr<const Response> &response,
		const std::string &name,
		const std::string &value
	);

	// Secondary ctor for multiple params
	template<class ... T>
	ParamResponse(
		const std::shared_ptr<const Response> &response,
		const std::string &name1,
		const std::string &value1,
		const std::string &name2,
		const T ... args
	) : ParamResponse(std::make_shared<ParamResponse>(response, name1, value1), name2, args...)
	{
	}

	std::string asString() const override;

private:
	const std::shared_ptr<const Response> response;
	const std::string name;
	const std::string value;
};

