// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetVersionEntry.h"
#include "ContentResponse.h"

using namespace std;

unique_ptr<const Response> GetVersionEntry::process(
	const shared_ptr<const HttpRequest> &request [[gnu::unused]]
) const
{
	// @todo #53 Return right server version
	return make_unique<ContentResponse>("0.0.0");
}
