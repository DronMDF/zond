// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// his software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MiningThread.h"
#include "ActiveScores.h"
#include "OptionSeconds.h"
#include "SuffixScore.h"

using namespace std;

MiningThread::MiningThread(
	const shared_ptr<ActiveScores> &scores,
	const shared_ptr<const Options> &options
) : scores(scores), options(options), go(true), thread(&MiningThread::routine, this)
{
}

MiningThread::~MiningThread()
{
	go = false;
	thread.join();
}

void MiningThread::routine() const
{
	const chrono::system_clock::duration mining_interval = OptionSeconds(options, "mining-interval");

	while (go) {
		try {
			const auto next = make_shared<SuffixScore>(
				scores->back(),
				options,
				mining_interval
			);
			scores->extend(next->suffixes().back());
		} catch (const exception &) {
			// Nothing to do.
			// try again
		}
	}
}
