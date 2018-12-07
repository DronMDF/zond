// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MethodCriterion.h"
#include "HttpRequest.h"

using namespace std;

MethodCriterion::MethodCriterion(const string &method)
	: method(method)
{
}

bool MethodCriterion::suitable(const shared_ptr<const HttpRequest> &request) const
{
	return request->method() == method;
}
