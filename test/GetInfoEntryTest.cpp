// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetInfoEntryTest.h"
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
			"GetInfoEntry reply contain platform field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(
						make_shared<FakeScores>(),
						// @todo #185 This options repited many times
						//  Need to introduce FakeOptions with test data
						make_shared<PredefinedOptions>(
							"mining-threads", "1",
							"protocol", "2",
							"strength", "8"
						)
					),
					make_shared<HttpRequest>("")
				),
				R"("platform":"null")"
			)
		),
		make_shared<TestNamed>(
			"GetInfoEntry reply contain cpus field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(
						make_shared<FakeScores>(),
						make_shared<PredefinedOptions>(
							"mining-threads", "1",
							"protocol", "2",
							"strength", "8"
						)
					),
					make_shared<HttpRequest>("")
				),
				R"("cpus":0)"
			)
		),
		make_shared<TestNamed>(
			"GetInfoEntry reply contain total_mem field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(
						make_shared<FakeScores>(),
						make_shared<PredefinedOptions>(
							"mining-threads", "1",
							"protocol", "2",
							"strength", "8"
						)
					),
					make_shared<HttpRequest>("")
				),
				R"("total_mem":)"
			)
		),
		make_shared<TestNamed>(
			"GetInfoEntry reply contain memory field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(
						make_shared<FakeScores>(),
						make_shared<PredefinedOptions>(
							"mining-threads", "1",
							"protocol", "2",
							"strength", "8"
						)
					),
					make_shared<HttpRequest>("")
				),
				R"("memory":)"
			)
		),
		make_shared<TestNamed>(
			"GetInfoEntry reply contain load field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(
						make_shared<FakeScores>(),
						make_shared<PredefinedOptions>(
							"mining-threads", "1",
							"protocol", "2",
							"strength", "8"
						)
					),
					make_shared<HttpRequest>("")
				),
				R"("load":)"
			)
		),
		make_shared<TestNamed>(
			"GetInfoEntry reply contain threads field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(
						make_shared<FakeScores>(),
						make_shared<PredefinedOptions>(
							"mining-threads", "1",
							"protocol", "2",
							"strength", "8"
						)
					),
					make_shared<HttpRequest>("")
				),
				R"("threads":)"
			)
		),
		make_shared<TestNamed>(
			"GetInfoEntry reply contain protocol field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(
						make_shared<FakeScores>(),
						make_shared<PredefinedOptions>(
							"mining-threads", "1",
							"protocol", "7",
							"strength", "8"
						)
					),
					make_shared<HttpRequest>("")
				),
				R"("protocol":7)"
			)
		),
		make_shared<TestNamed>(
			"GetInfoEntry reply contain score field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(
						make_shared<FakeScores>(),
						make_shared<PredefinedOptions>(
							"mining-threads", "1",
							"protocol", "2",
							"strength", "8"
						)
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
									"prefix-length", "8",
									"wallet", "777"
								)

							)
						),
						make_shared<PredefinedOptions>(
							"mining-threads", "1",
							"protocol", "2",
							"strength", "8"
						)
					),
					make_shared<HttpRequest>("")
				),
				R"("invoice":"pppppppp@777")"
			)
		)

	)
{
}
