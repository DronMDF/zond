// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ZoldProtocolEntry.h"
#include "StringHttpResponse.h"

using namespace std;

ZoldProtocolEntry::ZoldProtocolEntry(const shared_ptr<const Entry> &entry)
	: entry(entry)
{
}

unique_ptr<const HttpResponse> ZoldProtocolEntry::process(
	const shared_ptr<const HttpRequest> &request
) const
{
	// @todo #105 Add header field to Response - this is common patten.
	//  Need to extract this code to new class
	auto response = entry->process(request)->asString();
	return make_unique<StringHttpResponse>(
		response.insert(response.find("\r\n\r\n"), "\r\nZold-Score: todo")
	);
}
