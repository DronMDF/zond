// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StringScore.h"
#include <iterator>
#include <sstream>
#include "StringPrefix.h"

using namespace std;

StringScore::StringScore(const string &score)
	: score(score)
{
}

shared_ptr<const Prefix> StringScore::prefix() const
{
	return make_shared<StringPrefix>(score);
}

list<string> StringScore::suffixes() const
{
	istringstream in(score);
	list<string> sfx;
	copy(istream_iterator<string>(in), istream_iterator<string>(), back_inserter(sfx));
	auto it = sfx.begin();
	advance(it, 4);
	sfx.erase(sfx.begin(), it);
	return sfx;
}
