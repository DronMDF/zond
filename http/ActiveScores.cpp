// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ActiveScores.h"
#include <iostream>
#include "OptionSeconds.h"
#include "Prefix.h"
#include "ScoreString.h"
#include "ScoreValid.h"
#include "ServerScore.h"
#include "SuffixScore.h"

using namespace std;

ActiveScores::ActiveScores(const shared_ptr<const Options> &options)
	: options(options), active(make_shared<ServerScore>(options)), mined(active)
{
}

shared_ptr<const Score> ActiveScores::front() const
{
	return active;
}

shared_ptr<const Score> ActiveScores::back() const
{
	return mined;
}

ScoreIterator ActiveScores::begin() const
{
	return ScoreIterator(active, make_shared<ScoreIterator>(mined));
}

ScoreIterator ActiveScores::end() const
{
	return {};
}

void ActiveScores::renew()
{
	const chrono::system_clock::duration ttl = OptionSeconds(options, "score-livetime");
	if (active->prefix()->time() + ttl < chrono::system_clock::now()) {
		cout << "ActiveScores: expired score: " << ScoreString(active).value() << endl;
		active = mined;
	}

	const chrono::system_clock::duration ttm = OptionSeconds(options, "score-miningtime");
	if (mined->prefix()->time() + ttm < chrono::system_clock::now()) {
		mined = make_shared<ServerScore>(options);
		cout << "ActiveScores: new score for mining: " << ScoreString(mined).value() << endl;
	}
}

void ActiveScores::extend(const string &suffix)
{
	const auto next = make_shared<SuffixScore>(mined, suffix);
	if (ScoreValid(next)) {
		mined = next;
	}
}
