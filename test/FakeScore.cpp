// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FakeScore.h"
#include "../http/PredefinedOptions.h"
#include "../http/ServerScore.h"
#include "../http/SuffixScore.h"

using namespace std;

FakeScore::FakeScore(int rank)
	: score(
		make_score(
			make_shared<ServerScore>(
				make_shared<PredefinedOptions>(
					"host", "example.com",
					"port", "4096",
					"pubkey", string(1024, 'A'),
					"prefix-length", "8",
					"wallet", "1234567812345678"
				)
			),
			rank
		)
	)
{
}

shared_ptr<const Prefix> FakeScore::prefix() const
{
	return score->prefix();
}

list<string> FakeScore::suffixes() const
{
	return score->suffixes();
}

shared_ptr<const Score> FakeScore::make_score(const shared_ptr<const Score> &score, int rank) const
{
	if (rank == 0) {
		return score;
	}
	return make_score(
		make_shared<SuffixScore>(score, make_shared<PredefinedOptions>("strength", "3")),
		rank - 1
	);
}
