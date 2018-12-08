// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "AlwaysCriterion.h"

using namespace std;

bool AlwaysCriterion::suitable(const shared_ptr<const HttpRequest> &request [[gnu::unused]]) const
{
	return true;
}
