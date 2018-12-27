// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "PrefixString.h"

using namespace std;

PrefixString::PrefixString(const shared_ptr<const Prefix> &prefix)
	: prefix(prefix)
{
}

string PrefixString::value() const
{
	// @todo #123 Create string representation for prefix
	return "unknown prefix";
}
