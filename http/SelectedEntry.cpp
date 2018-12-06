// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SelectedEntry.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "NotFoundEntry.h"

using namespace std;

SelectedEntry::SelectedEntry(
	const string &method,
	const string &uri_pattern,
	const shared_ptr<const Entry> &entry,
	const shared_ptr<const Entry> &fallback
) : method(method), uri_pattern(uri_pattern), entry(entry), fallback(fallback)
{
}

SelectedEntry::SelectedEntry(
	const string &method,
	const string &uri_pattern,
	const shared_ptr<const Entry> &entry
) : SelectedEntry(method, uri_pattern, entry, make_shared<NotFoundEntry>())
{
}
unique_ptr<const HttpResponse> SelectedEntry::process(
	const shared_ptr<const HttpRequest> &request
) const
{
	// @todo #59 Select entry by method
	// @todo #59 Select entry by uri by regexp
	if (request->uri() == uri_pattern) {
		return entry->process(request);
	}
	return fallback->process(request);
}
