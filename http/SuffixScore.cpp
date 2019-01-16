// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SuffixScore.h"

using namespace std;

SuffixScore::SuffixScore(const shared_ptr<const Score> &score, const string &suffix)
	: score(score), suffix(suffix)
{
}

shared_ptr<const Prefix> SuffixScore::prefix() const
{
	return score->prefix();
}

list<string> SuffixScore::suffixes() const
{
	auto suffixes = score->suffixes();
	suffixes.push_back(suffix);
	return suffixes;
}
