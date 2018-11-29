// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StringHttpResponse.h"

using namespace std;

StringHttpResponse::StringHttpResponse(const string &response)
	: response(response)
{
}

string StringHttpResponse::asString() const
{
	return response;
}
