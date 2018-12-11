// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Entry.h"

class GetRemotesEntry final : public Entry {
public:
	std::unique_ptr<const HttpResponse> process(
		const std::shared_ptr<const HttpRequest> &request
	) const override;
};
