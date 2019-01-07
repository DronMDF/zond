// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "../http/Entry.h"

class FakeEntry final : public Entry {
public:
	explicit FakeEntry(const std::string &text);
	std::unique_ptr<const Response> process(
		const std::shared_ptr<const HttpRequest> &request
	) const override;
private:
	const std::string text;
};
