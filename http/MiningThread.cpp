// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// his software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MiningThread.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <openssl/sha.h>
#include "ActiveScores.h"
#include "OptionInt.h"
#include "OptionSeconds.h"
#include "ScoreString.h"

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
	cout << "Start mining thread: " << this_thread::get_id() << endl;
	const chrono::system_clock::duration mining_interval = OptionSeconds(options, "mining-interval");
	const auto strength = OptionInt(options, "strength");

	random_device rd;
	default_random_engine re(rd());
	uniform_int_distribution<uint64_t> rn(0, 0xffffffff);

	while (go) {
		const auto ct = chrono::system_clock::now() + mining_interval;
		uint64_t nonce = rn(re);

		const auto score = scores->back();
		const auto base = ScoreString(score).value() + " ";

		SHA256_CTX ctx;
		SHA256_Init(&ctx);
		SHA256_Update(&ctx, base.data(), base.size());

		while (chrono::system_clock::now() < ct) {
			SHA256_CTX lctx = ctx;
			const auto suffix = to_string(nonce);
			SHA256_Update(&lctx, suffix.data(), suffix.size());
			array<uint8_t, SHA256_DIGEST_LENGTH> hash;
			SHA256_Final(&hash[0], &lctx);

			const auto nz = find_if_not(
				hash.rbegin(),
				hash.rend(),
				[](uint8_t v){ return v == 0; }
			);
			const auto zeroes = distance(hash.rbegin(), nz)
				+ ((nz != hash.rend() && (*nz & 0xf0) == 0) ? 1 : 0);

			if (zeroes >= strength) {
				scores->extend(suffix);
				break;
			}

			nonce++;
		}
	}
}
