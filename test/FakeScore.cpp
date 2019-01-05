// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FakeScore.h"
#include "../http/PredefinedOptions.h"
#include "../http/ServerPrefix.h"

using namespace std;

FakeScore::FakeScore(size_t strength)
	: strength(strength)
{
}

shared_ptr<const Prefix> FakeScore::prefix() const
{
	return make_shared<ServerPrefix>(
		make_shared<PredefinedOptions>(
			"host", "example.com",
			"port", "4096",
			"pubkey", string(1024, 'A'),
			"wallet", "1234567812345678"
		)
	);
}

list<string> FakeScore::suffixes() const
{
	return {strength, "fakesuffix"};
}
