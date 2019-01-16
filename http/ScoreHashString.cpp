// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreHashString.h"
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
#include "Score.h"
#include "Prefix.h"
#include "PrefixString.h"

using namespace std;

ScoreHashString::ScoreHashString(const shared_ptr<const Score> &score)
	: score(score)
{
}

ScoreHashString::operator std::string() const
{
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
	}
	return base;
}
