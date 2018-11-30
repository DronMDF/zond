// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetVersionEntry.h"
#include "StringHttpResponse.h"

using namespace std;

unique_ptr<const HttpResponse> GetVersionEntry::process() const
{
	// @todo #53 Return right server version
	return make_unique<StringHttpResponse>(
		"HTTP/1.1 200 Ok\r\n"
		"Content-Type: text/plain\r\n"
		"Content-Length: 5\r\n"
		"\r\n"
		"0.0.0"
	);
}
