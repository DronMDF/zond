// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Criterion.h"

class EqualCriterion final : public Criterion {
public:
	explicit EqualCriterion(const std::string &uri);
	bool suitable(const std::shared_ptr<const HttpRequest> &request) const override;
private:
	const std::string uri;
};
