// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FakeEntry.h"
#include "../http/RawResponse.h"

using namespace std;

FakeEntry::FakeEntry(const string &text)
	: text(text)
{
}

unique_ptr<const Response> FakeEntry::process(
	const shared_ptr<const HttpRequest> &request [[gnu::unused]]
) const
{
	return make_unique<RawResponse>(text);
}
