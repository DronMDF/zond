// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Entry.h"

class Criterion;

class SelectedEntry final : public Entry {
public:
	// Primary ctor
	SelectedEntry(
		const std::shared_ptr<const Criterion> &criterion,
		const std::shared_ptr<const Entry> &entry,
		const std::shared_ptr<const Entry> &fallback
	);

	// Secondary ctor with 404 at fallback
	SelectedEntry(
		const std::shared_ptr<const Criterion> &criterion,
		const std::shared_ptr<const Entry> &entry
	);

	// Secondary ctor for chaining
	template<class ... T>
	SelectedEntry(
		const std::shared_ptr<const Criterion> &criterion,
		const std::shared_ptr<const Entry> &entry,
		const std::shared_ptr<const Criterion> &criterion2,
		T ... args
	) : SelectedEntry(criterion, entry, std::make_shared<SelectedEntry>(criterion2, args...))
	{
	}

	std::unique_ptr<const Response> process(
		const std::shared_ptr<const HttpRequest> &request
	) const override;

private:
	const std::shared_ptr<const Criterion> criterion;
	const std::shared_ptr<const Entry> entry;
	const std::shared_ptr<const Entry> fallback;
};
