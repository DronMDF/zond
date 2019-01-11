// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// his software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <vector>

class ActiveScores;
class MiningThread;
class Options;

class MiningPool final {
public:
	MiningPool(
		const std::shared_ptr<const Options> &options,
		const std::shared_ptr<ActiveScores> &scores
	);
	~MiningPool();

private:
	const std::shared_ptr<const Options> options;
	const std::shared_ptr<ActiveScores> scores;
	std::vector<std::shared_ptr<const MiningThread>> threads;
};
