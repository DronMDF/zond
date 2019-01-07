// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EqualCriterion.h"
#include "HttpRequest.h"

using namespace std;

EqualCriterion::EqualCriterion(const string &uri)
	: uri(uri)
{
}

bool EqualCriterion::suitable(const shared_ptr<const HttpRequest> &request) const
{
	return request->uri() == uri;
}
