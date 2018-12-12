// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetInfoEntry.h"
#include <nlohmann/json.hpp>
#include "StringHttpResponse.h"

using namespace std;

unique_ptr<const HttpResponse> GetInfoEntry::process(
	const shared_ptr<const HttpRequest> &request [[gnu::unused]]
) const
{
	// @todo #82 Add Score to Info response
	// @todo #98 Create HttpResponse header by content
	//  Question about Content-Length
	return make_unique<StringHttpResponse>(
		"HTTP/1.1 200 Ok\r\n"
		"Content-Type: application/json\r\n"
		"Content-Length: 2\r\n"
		"\r\n"
		+ nlohmann::json::object().dump()
	);
}
