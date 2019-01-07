// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "NotFoundEntry.h"
#include "RawResponse.h"

using namespace std;

unique_ptr<const Response> NotFoundEntry::process(
	const shared_ptr<const HttpRequest> &request [[gnu::unused]]
) const
{
	return make_unique<RawResponse>(
		"HTTP/1.1 404 Not Found\r\n"
		"Content-Type: text/plain\r\n"
		"Content-Length: 9\r\n"
		"\r\n"
		"Not Found"
	);
}
