// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <memory>
#include <thread>
#include "../http/PredefinedOptions.h"
#include "../http/StringScore.h"
#include "../http/SuffixScore.h"

using namespace std;

// @todo #202 Create miner invoker (as python script)

int main(int argc [[gnu::unused]], char **argv)
{
	// @todo #202 MiningPool cannot be used in miner context
	//  MiningPool use extended ActiveScores API. How to emulate it?
	const auto score = make_shared<SuffixScore>(
		make_shared<StringScore>(argv[1]),
		make_shared<PredefinedOptions>(
			"strength", "8",
			"mining-threads", to_string(thread::hardware_concurrency()),
			"mining-interval", "10"
		)
	);
	cout << score->suffixes().back() << endl;
	return 0;
}
