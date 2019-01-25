// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetInfoEntryTest.h"
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include "../http/GetInfoEntry.h"
#include "../http/HttpRequest.h"
#include "../http/PredefinedOptions.h"
#include "../http/ServerScore.h"
#include "EntryRepr.h"
#include "FakeScores.h"

using namespace std;
using namespace oout;

GetInfoEntryTest::GetInfoEntryTest()
	: TestSuite(
		make_shared<TestNamed>(
			"GetInfoEntry reply contain score field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(
						make_shared<FakeScores>(),
						make_shared<PredefinedOptions>("strength", "8")
					),
					make_shared<HttpRequest>("")
				),
				R"("score":{)"
			)
		),
		make_shared<TestNamed>(
			"GetInfoEntry reply contain score content",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(
						make_shared<FakeScores>(
							make_shared<ServerScore>(
								make_shared<PredefinedOptions>(
									"host", "host",
									"port", "777",
									"pubkey", "pppppppp",
									"wallet", "777"
								)

							)
						),
						make_shared<PredefinedOptions>("strength", "8")
					),
					make_shared<HttpRequest>("")
				),
				R"("invoice":"pppppppp@777")"
			)
		)

	)
{
}
