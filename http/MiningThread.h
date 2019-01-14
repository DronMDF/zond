// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// his software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <thread>

class ActiveScores;
class Options;

class MiningThread final {
public:
	MiningThread(
		const std::shared_ptr<ActiveScores> &scores,
		const std::shared_ptr<const Options> &options
	);

	~MiningThread();

private:
	const std::shared_ptr<ActiveScores> scores;
	const std::shared_ptr<const Options> options;
	std::thread thread;
};
