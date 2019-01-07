// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StrongestScoresTest.h"
#include <2out/TestNamed.h>
#include <2out/TestContainText.h>
#include "../http/StrongestScores.h"
#include "FakeScore.h"
#include "FakeScores.h"
#include "ScoresFrontRepr.h"

using namespace oout;
using namespace std;

StrongestScoresTest::StrongestScoresTest()
	: TestSuite(
		make_shared<TestNamed>(
			"StrongestScore select last score from Scores",
			make_shared<TestContainText>(
				make_shared<ScoresFrontRepr>(
					make_shared<StrongestScores>(
						make_shared<FakeScores>(
							make_shared<FakeScore>(3),
							make_shared<FakeScore>(5)
						)
					)
				),
				"fakesuffix fakesuffix fakesuffix fakesuffix fakesuffix"
			)
		)
	)
{
}

