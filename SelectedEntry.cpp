// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SelectedEntry.h"
#include "HttpResponse.h"

using namespace std;

SelectedEntry::SelectedEntry(
	const shared_ptr<const Entry> &entry1,
	const shared_ptr<const Entry> &entry2
) : entry1(entry1), entry2(entry2)
{
}

unique_ptr<const HttpResponse> SelectedEntry::process() const
{
	// @todo #53 Select right entry by request
	return entry1->process();
}
