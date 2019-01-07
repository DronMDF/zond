// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CriterionRepr.h"
#include "../http/Criterion.h"

using namespace std;

CriterionRepr::CriterionRepr(
	const shared_ptr<const Criterion> &criterion,
	const shared_ptr<const HttpRequest> &request
) : criterion(criterion), request(request)
{
}

string CriterionRepr::asString() const
{
	return criterion->suitable(request) ? "suitable" : "unsuitable";
}
