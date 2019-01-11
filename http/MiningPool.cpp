// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// his software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MiningPool.h"
#include "MiningThread.h"
#include "OptionInt.h"

using namespace std;

MiningPool::MiningPool(
	const shared_ptr<const Options> &options,
	const shared_ptr<ActiveScores> &scores
) : options(options), scores(scores), threads(OptionInt(options, "mining-threads"))
{
	for (auto &t : threads) {
		t = make_shared<MiningThread>(scores, options);
	}
}

MiningPool::~MiningPool()
{
	for (auto &t : threads) {
		t.reset();
	}
}
