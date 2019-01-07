// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Options.h"

class MultipleSourcesOptions final : public Options {
public:
	MultipleSourcesOptions(
		const std::shared_ptr<const Options> &options,
		const std::shared_ptr<const Options> &fallback
	);

	std::string value(const std::string &name) const override;
	bool enabled(const std::string &name) const override;
private:
	const std::shared_ptr<const Options> options;
	const std::shared_ptr<const Options> fallback;
};
