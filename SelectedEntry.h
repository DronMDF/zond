// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Entry.h"

class SelectedEntry final : public Entry {
public:
	SelectedEntry(
		const std::shared_ptr<const Entry> &entry1,
		const std::shared_ptr<const Entry> &entry2
	);
	std::unique_ptr<const HttpResponse> process() const override;
private:
	const std::shared_ptr<const Entry> entry1;
	const std::shared_ptr<const Entry> entry2;
};
