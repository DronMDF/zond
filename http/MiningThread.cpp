// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// his software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MiningThread.h"

using namespace std;

MiningThread::MiningThread(
	const shared_ptr<ActiveScores> &scores,
	const shared_ptr<const Options> &options
) : scores(scores), options(options)
{
	// @todo #154 Implement MiningThread
}

MiningThread::~MiningThread()
{
}
