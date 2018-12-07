// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Entry.h"

class Criterion;

class SelectedEntry final : public Entry {
public:
	SelectedEntry(
		const std::shared_ptr<const Criterion> &criterion,
		const std::shared_ptr<const Entry> &entry,
		const std::shared_ptr<const Entry> &fallback
	);
	SelectedEntry(
		const std::shared_ptr<const Criterion> &criterion,
		const std::shared_ptr<const Entry> &entry
	);
	// @todo #59 Create chained ctor for SelectedEntry
	//  Like this:
	//  SelectedEntry(
	//  _"GET", "/version", entry1,
	//  _"PUT", "/wallet/, entry2,
	//  _...
	//  )

	std::unique_ptr<const HttpResponse> process(
		const std::shared_ptr<const HttpRequest> &request
	) const override;

private:
	const std::shared_ptr<const Criterion> criterion;
	const std::shared_ptr<const Entry> entry;
	const std::shared_ptr<const Entry> fallback;
};
