// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SuffixScore.h"
#include <algorithm>
#include <random>
#include <openssl/sha.h>
#include "OptionInt.h"
#include "ScoreHashString.h"

using namespace std;

SuffixScore::SuffixScore(const shared_ptr<const Score> &score, const string &suffix)
	: score(score), suffix(suffix)
{
}

SuffixScore::SuffixScore(
	const shared_ptr<const Score> &score,
	const shared_ptr<const Options> &options,
	const chrono::system_clock::duration &timeout
) : SuffixScore(score, make_suffix(score, options, timeout))
{
}

SuffixScore::SuffixScore(
	const shared_ptr<const Score> &score,
	const shared_ptr<const Options> &options
) : SuffixScore(score, options, 24h)
{
}

shared_ptr<const Prefix> SuffixScore::prefix() const
{
	return score->prefix();
}

list<string> SuffixScore::suffixes() const
{
	auto suffixes = score->suffixes();
	suffixes.push_back(suffix);
	return suffixes;
}

// @todo #202 Mined suffixes are wrong
//  may be ScoreHashString have bug?
string SuffixScore::make_suffix(
	const shared_ptr<const Score> &score,
	const shared_ptr<const Options> &options,
	const chrono::system_clock::duration &timeout
)
{
	const int strength = OptionInt(options, "strength");

	const auto ct = chrono::system_clock::now() + timeout;
	const auto base = string(ScoreHashString(score)) + " ";

	random_device rd;
	default_random_engine re(rd());
	uniform_int_distribution<uint64_t> rn(0, 0xffffffff);
	uint64_t nonce = rn(re);

	SHA256_CTX ctx;
	SHA256_Init(&ctx);
	SHA256_Update(&ctx, base.data(), base.size());

	while (chrono::system_clock::now() < ct) {
		SHA256_CTX lctx = ctx;
		// @todo #165 to_string is ugly in scode string
		const auto suffix = to_string(nonce);
		SHA256_Update(&lctx, suffix.data(), suffix.size());
		array<uint8_t, SHA256_DIGEST_LENGTH> hash;
		SHA256_Final(&hash[0], &lctx);

		const auto nz = find_if_not(
			hash.rbegin(),
			hash.rend(),
			[](uint8_t v){ return v == 0; }
		);
		const auto zeroes = distance(hash.rbegin(), nz) * 2
			+ ((nz != hash.rend() && (*nz & 0xf) == 0) ? 1 : 0);

		if (zeroes >= strength) {
			return suffix;
		}
		nonce++;
	}

	throw runtime_error("Score suffix not found in given time");
}
