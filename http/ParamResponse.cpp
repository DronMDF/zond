// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ParamResponse.h"

using namespace std;

ParamResponse::ParamResponse(
	const shared_ptr<const Response> &response,
	const string &name,
	const string &value
) : response(response), name(name), value(value)
{
}

string ParamResponse::asString() const
{
	auto text = response->asString();
	return text.insert(text.find("\r\n\r\n"), "\r\n" + name + ": " + value);
}
