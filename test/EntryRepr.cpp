// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EntryRepr.h"
#include "../http/Entry.h"
#include "../http/Response.h"

using namespace std;

EntryRepr::EntryRepr(
	const shared_ptr<const Entry> &entry,
	const shared_ptr<const HttpRequest> &request
) : entry(entry), request(request)
{
}

string EntryRepr::asString() const
{
	return entry->process(request)->asString();
}
