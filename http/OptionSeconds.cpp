// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "OptionSeconds.h"
#include "OptionInt.h"

using namespace std;

OptionSeconds::OptionSeconds(const shared_ptr<const Options> &options, const string &name)
	: options(options), name(name)
{
}

OptionSeconds::operator chrono::system_clock::duration() const
{
	return chrono::seconds(OptionInt(options, name));
}
