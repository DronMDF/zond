// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <string>

class Options;

// @todo #152 Now, by analogy with IntOption, need to introduce StringOption, EnableOption
class IntOption final {
public:
	IntOption(const std::shared_ptr<const Options> &options, const std::string &name);
	operator int() const;
private:
	const std::shared_ptr<const Options> options;
	const std::string name;
};
