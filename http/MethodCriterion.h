// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Criterion.h"

class MethodCriterion final : public Criterion {
public:
	// @todo #74 MethodCriterion should wrap other Criterion
	explicit MethodCriterion(const std::string &method);
	bool suitable(const std::shared_ptr<const HttpRequest> &request) const override;
private:
	const std::string method;
};
