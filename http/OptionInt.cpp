// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "OptionInt.h"
#include "Options.h"

using namespace std;

OptionInt::OptionInt(const shared_ptr<const Options> &options, const string &name)
	: options(options), name(name)
{
}

OptionInt::operator int() const
{
	return atoi(options->value(name).c_str());
}
