// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Response.h"

class RawResponse final : public Response {
public:
	explicit RawResponse(const std::string &reponse);
	std::string asString() const override;
private:
	const std::string response;
};
