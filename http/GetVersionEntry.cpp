// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetVersionEntry.h"
#include "ContentResponse.h"
#include "Options.h"

using namespace std;

GetVersionEntry::GetVersionEntry(const shared_ptr<const Options> &options)
	: options(options)
{
}

unique_ptr<const Response> GetVersionEntry::process(
	const shared_ptr<const HttpRequest> &request [[gnu::unused]]
) const
{
	return make_unique<ContentResponse>(options->value("version"));
}
