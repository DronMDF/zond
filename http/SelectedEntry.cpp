// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SelectedEntry.h"
#include "Criterion.h"
#include "HttpRequest.h"
#include "Response.h"
#include "NotFoundEntry.h"

using namespace std;

SelectedEntry::SelectedEntry(
	const shared_ptr<const Criterion> &criterion,
	const shared_ptr<const Entry> &entry,
	const shared_ptr<const Entry> &fallback
) : criterion(criterion), entry(entry), fallback(fallback)
{
}

SelectedEntry::SelectedEntry(
	const shared_ptr<const Criterion> &criterion,
	const shared_ptr<const Entry> &entry
) : SelectedEntry(criterion, entry, make_shared<NotFoundEntry>())
{
}
unique_ptr<const Response> SelectedEntry::process(
	const shared_ptr<const HttpRequest> &request
) const
{
	// @todo #59 Select entry by uri by regexp
	if (criterion->suitable(request)) {
		return entry->process(request);
	}
	return fallback->process(request);
}
