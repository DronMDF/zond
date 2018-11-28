// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "NotFoundEntry.h"

using namespace std;

string NotFoundEntry::process() const
{
	return "HTTP/1.1 404 Not Found\r\n"
		"Content-Type: text/plain\r\n"
		"Content-Length: 9\r\n"
		"\r\n"
		"Not Found";
}
