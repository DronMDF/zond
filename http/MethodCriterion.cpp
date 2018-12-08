// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MethodCriterion.h"
#include "AlwaysCriterion.h"
#include "HttpRequest.h"

using namespace std;

MethodCriterion::MethodCriterion(const string &method, const shared_ptr<const Criterion> &criterion)
	: method(method), criterion(criterion)
{
}

MethodCriterion::MethodCriterion(const string &method)
	: MethodCriterion(method, make_shared<AlwaysCriterion>())
{
}

bool MethodCriterion::suitable(const shared_ptr<const HttpRequest> &request) const
{
	return request->method() == method && criterion->suitable(request);
}
