// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StringScoreTest.h"
#include <2out/TestNamed.h>
#include <2out/TestStartsWith.h>
#include "../http/StringScore.h"
#include "ScoreRepr.h"

using namespace std;
using namespace oout;

StringScoreTest::StringScoreTest()
	: TestSuite(
		make_shared<TestNamed>(
			"StringScore should correct parse time, in UTC",
			make_shared<TestStartsWith>(
				make_shared<ScoreRepr>(
					make_shared<StringScore>(
						"2019-01-29T07:26:15Z localhost 4096 "
						"publicke@ffffffffffffffff"
					)
				),
				"2019-01-29T07:26:15Z "
			)
		)
	)
{
}
