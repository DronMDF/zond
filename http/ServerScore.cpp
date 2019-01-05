// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ServerScore.h"
#include "ServerPrefix.h"

using namespace std;

ServerScore::ServerScore(const shared_ptr<const Options> &options)
	: _prefix(make_shared<ServerPrefix>(options))
{
}

shared_ptr<const Prefix> ServerScore::prefix() const
{
	return _prefix;
}

// ServerScore always return empty suffixes.
// new suffixes add over decorators
list<string> ServerScore::suffixes() const
{
	return {};
}
