// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "RawResponse.h"

using namespace std;

RawResponse::RawResponse(const string &response)
	: response(response)
{
}

string RawResponse::asString() const
{
	return response;
}
