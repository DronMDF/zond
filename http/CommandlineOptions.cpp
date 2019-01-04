// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CommandlineOptions.h"
#include <algorithm>

using namespace std;

CommandlineOptions::CommandlineOptions(const list<string> &options)
	: options(options)
{
}

bool CommandlineOptions::enabled(const string &name) const
{
	return find(options.begin(), options.end(), "--enable-" + name) != options.end();
}
