// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "NoOptions.h"
#include <stdexcept>

using namespace std;

string NoOptions::value(const string &name) const
{
	throw runtime_error("NoOptions: Unspecified option '" + name + "'");
}

bool NoOptions::enabled(const std::string &name [[gnu::unused]]) const
{
	return false;
}
