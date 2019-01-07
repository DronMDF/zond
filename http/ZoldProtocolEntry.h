// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Entry.h"

class Scores;
class Options;

class ZoldProtocolEntry final : public Entry {
public:
	// Primary ctor
	ZoldProtocolEntry(
		const std::shared_ptr<const Entry> &entry,
		const std::shared_ptr<const Scores> &scores,
		const std::shared_ptr<const Options> &options
	);

	// Ctor without options
	// All extension are disabled
	ZoldProtocolEntry(
		const std::shared_ptr<const Entry> &entry,
		const std::shared_ptr<const Scores> &scores
	);

	std::unique_ptr<const Response> process(
		const std::shared_ptr<const HttpRequest> &request
	) const override;

private:
	const std::shared_ptr<const Entry> entry;
	const std::shared_ptr<const Scores> scores;
	const std::shared_ptr<const Options> options;
};
