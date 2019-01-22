// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "HashString.h"
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

HashString::HashString(const string &str)
	: str(str)
{
}

HashString::HashString(const string &base, const string &suffix)
	: HashString(base + " " + suffix)
{
}

HashString::operator string() const
{
	SHA256_CTX ctx;
	SHA256_Init(&ctx);
	SHA256_Update(&ctx, str.data(), str.size());
	array<uint8_t, SHA256_DIGEST_LENGTH> hash;
	SHA256_Final(&hash[0], &ctx);

	ostringstream hl;
	for (const auto &h : hash) {
		hl << hex << setw(2) << setfill('0') << int(h);
	}
	return hl.str();
}
