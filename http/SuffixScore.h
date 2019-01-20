// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Score.h"
#include <chrono>

class Options;

class SuffixScore final : public Score {
public:
	SuffixScore(const std::shared_ptr<const Score> &score, const std::string &suffix);
	SuffixScore(
		const std::shared_ptr<const Score> &score,
		const std::shared_ptr<const Options> &options,
		const std::chrono::system_clock::duration &timeout
	);
	SuffixScore(
		const std::shared_ptr<const Score> &score,
		const std::shared_ptr<const Options> &options
	);

	std::shared_ptr<const Prefix> prefix() const override;
	std::list<std::string> suffixes() const override;

private:
	const std::shared_ptr<const Score> score;
	const std::string suffix;

	// make_suffix search new suffix for given score
	// after timeout this method cause exception
	std::string make_suffix(
		const std::shared_ptr<const Score> &score,
		const std::shared_ptr<const Options> &options,
		const std::chrono::system_clock::duration &timeout
	);
};
