// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "HttpHeader.h"
#include <regex>

using namespace std;

HttpHeader::HttpHeader(const string &header)
	: header(header)
{
}

string HttpHeader::getField(const string &name, const string &default_value) const
{
	smatch match;
	regex rx(R"(\r\n)" + name + R"(:\s+(.*)\s*\r\n)", regex_constants::icase);
	if (regex_search(header, match, rx)) {
		return match[1];
	}
	return default_value;
}
