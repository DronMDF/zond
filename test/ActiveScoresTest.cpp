// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ActiveScoresTest.h"
#include "../http/ActiveScores.h"
#include "../http/PredefinedOptions.h"
#include "ScoresFrontRepr.h"

using namespace std;
using namespace oout;

ActiveScoresTest::ActiveScoresTest()
	: TestSuite(
		make_shared<TestNamed>(
			"ActiveScores always return score with given wallet",
			make_shared<TestContainText>(
				make_shared<ScoresFrontRepr>(
					make_shared<ActiveScores>(
						make_shared<PredefinedOptions>(
							"host", "example.com",
							"port", "4096",
							"pubkey", string(1024, 'A'),
							"prefix-length", "8",
							"wallet", "1234567812345678"
						)
					)
				),
				" example.com 4096 AAAAAAAA@1234567812345678"
			)
		)
	)
{
}
