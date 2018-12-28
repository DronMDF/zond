// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "NoOptions.h"

using namespace std;

bool NoOptions::enabled(const std::string &name [[gnu::unused]]) const
{
	return false;
}
