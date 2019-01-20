// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreValid.h"
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>
#include "OptionInt.h"
#include "OptionSeconds.h"
#include "Prefix.h"
#include "PrefixString.h"
#include "Score.h"
#include "ScoreHashString.h"
#include "Strength.h"

using namespace std;

ScoreValid::ScoreValid(
	const shared_ptr<const Score> &score,
	const shared_ptr<const Options> &options
) : score(score), options(options)
{
}

ScoreValid::operator bool() const
{
	const chrono::system_clock::duration ttl = OptionSeconds(options, "score-livetime");
	if (score->prefix()->time() + ttl < chrono::system_clock::now()) {
		return false;
	}

	string base = PrefixString(score->prefix()).value();
	for (const auto &s : score->suffixes()) {
		string line = base + " " + s;
		SHA256_CTX ctx;
		SHA256_Init(&ctx);
		SHA256_Update(&ctx, line.data(), line.size());
		array<uint8_t, SHA256_DIGEST_LENGTH> hash;
		SHA256_Final(&hash[0], &ctx);

		ostringstream hl;
		for (const auto &h : hash) {
			hl << hex << setw(2) << setfill('0') << int(h);
		}
		base = hl.str();
		if (Strength(base) < OptionInt(options, "strength")) {
			return false;
		}
	}
	return true;
}
