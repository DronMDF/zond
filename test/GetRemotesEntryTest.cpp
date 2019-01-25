// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetRemotesEntryTest.h"
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include "../http/GetRemotesEntry.h"
#include "../http/HttpRequest.h"
#include "../http/PredefinedOptions.h"
#include "EntryRepr.h"
#include "FakeScores.h"

using namespace std;
using namespace oout;

GetRemotesEntryTest::GetRemotesEntryTest()
	: TestSuite(
		make_shared<TestNamed>(
			"GetRemotesEntry reply contain score field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetRemotesEntry>(
						make_shared<FakeScores>(),
						make_shared<PredefinedOptions>(
							"strength", "8",
							"version", "3.2.1"
						)
					),
					make_shared<HttpRequest>("")
				),
				R"("score":{)"
			)
		),
		make_shared<TestNamed>(
			"GetRemotesEntry reply contain version field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetRemotesEntry>(
						make_shared<FakeScores>(),
						make_shared<PredefinedOptions>(
							"strength", "8",
							"version", "1.2.3"
						)
					),
					make_shared<HttpRequest>("")
				),
				R"("version":"1.2.3")"
			)
		)
	)
{
}
