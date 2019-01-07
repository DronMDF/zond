// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>

class Criterion;
class HttpRequest;

// This class represent as "suitable" if criteria is suitable for request
// and "unsuitable" if not.
class CriterionRepr final : public oout::Representation {
public:
	CriterionRepr(
		const std::shared_ptr<const Criterion> &criterion,
		const std::shared_ptr<const HttpRequest> &request
	);

	std::string asString() const override;
private:
	const std::shared_ptr<const Criterion> criterion;
	const std::shared_ptr<const HttpRequest> request;
};

