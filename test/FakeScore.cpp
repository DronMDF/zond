// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FakeScore.h"

using namespace std;

FakeScore::FakeScore(size_t strength)
	: strength(strength)
{
}

shared_ptr<const Prefix> FakeScore::prefix() const
{
	return {};
}

list<string> FakeScore::suffixes() const
{
	return {strength, "fakesuffix"};
}
