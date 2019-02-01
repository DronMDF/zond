// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/2out.h>

class Entry;
class HttpRequest;

class EntryRepr final : public oout::Representation {
public:
	EntryRepr(
		const std::shared_ptr<const Entry> &entry,
		const std::shared_ptr<const HttpRequest> &request
	);
	std::string asString() const override;
private:
	const std::shared_ptr<const Entry> entry;
	const std::shared_ptr<const HttpRequest> request;
};
