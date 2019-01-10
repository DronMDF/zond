// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ActiveScores.h"
#include <iostream>
#include "Options.h"
#include "Prefix.h"
#include "ScoreString.h"
#include "ServerScore.h"

using namespace std;

ActiveScores::ActiveScores(const shared_ptr<const Options> &options)
	: options(options), active(make_shared<ServerScore>(options)), mined(active)
{
}

shared_ptr<const Score> ActiveScores::front() const
{
	return active;
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
	const auto score_livetime = chrono::seconds(atoi(options->value("score-livetime").c_str()));
	if (active->prefix()->time() + score_livetime < chrono::system_clock::now()) {
		cout << "ActiveScores: expired score: " << ScoreString(active).value() << endl;
		active = mined;
	}

	const auto score_miningtime = chrono::seconds(atoi(options->value("score-miningtime").c_str()));
	if (mined->prefix()->time() + score_miningtime < chrono::system_clock::now()) {
		mined = make_shared<ServerScore>(options);
		cout << "ActiveScores: new score for mining: " << ScoreString(mined).value() << endl;
	}
}
