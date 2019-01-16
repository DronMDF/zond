// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Strength.h"
#include <algorithm>

using namespace std;

Strength::Strength(const string &hash)
	: hash(hash)
{
}

Strength::operator int() const
{
	return distance(
		hash.rbegin(),
		find_if_not(hash.rbegin(), hash.rend(), [](const auto &c){ return c == '0'; })
	);
}
