// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetInfoEntry.h"
#include <nlohmann/json.hpp>
#include "ContentResponse.h"

using namespace std;

unique_ptr<const Response> GetInfoEntry::process(
	const shared_ptr<const HttpRequest> &request [[gnu::unused]]
) const
{
	// @todo #82 Add Score to Info response
	return make_unique<ContentResponse>(nlohmann::json::object());
}
