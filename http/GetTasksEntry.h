// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Entry.h"

class ActiveScores;
class Options;

class GetTasksEntry final : public Entry {
public:
	GetTasksEntry(
		const std::shared_ptr<const ActiveScores> &scores,
		const std::shared_ptr<const Options> &options
	);
	std::unique_ptr<const Response> process(
		const std::shared_ptr<const HttpRequest> &request
	) const override;
private:
	const std::shared_ptr<const ActiveScores> scores;
	const std::shared_ptr<const Options> options;
};
