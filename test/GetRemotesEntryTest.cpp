// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetRemotesEntryTest.h"
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include "../http/GetRemotesEntry.h"
#include "../http/HttpRequest.h"
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
						make_shared<FakeScores>()
					),
					make_shared<HttpRequest>("")
				),
				R"("score":{)"
			)
		)
	)
{
}
