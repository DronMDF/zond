// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "HttpHeader.h"

using namespace std;

HttpHeader::HttpHeader(const string &header [[gnu::unused]])
{
}

string HttpHeader::getField(const string &name [[gnu::unused]]) const
{
	// @todo #35 Get field value from header content
	return "0";
}
