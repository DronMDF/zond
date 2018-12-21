// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ZoldProtocolEntry.h"
#include "ParamResponse.h"

using namespace std;

ZoldProtocolEntry::ZoldProtocolEntry(const shared_ptr<const Entry> &entry)
	: entry(entry)
{
}

unique_ptr<const Response> ZoldProtocolEntry::process(
	const shared_ptr<const HttpRequest> &request
) const
{
	return make_unique<ParamResponse>(
		entry->process(request),
		"X-Zold-Protocol", "2",
		// @todo #111 Set server version
		"X-Zold-Version", "0.0.0",
		"X-Zold-Repo", "DronMDF/zond",
		// @todo #111 Set current server score
		"X-Zold-Score", "todo"
	);
}
