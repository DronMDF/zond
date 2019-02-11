// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetInfoEntryTest.h"
#include "../http/GetInfoEntry.h"
#include "../http/HttpRequest.h"
#include "EntryRepr.h"
#include "FakeOptions.h"
#include "FakeScores.h"

using namespace std;
using namespace oout;

GetInfoEntryTest::GetInfoEntryTest()
	: TestSuite(
		make_shared<TestNamed>(
			"GetInfoEntry reply contain necessary fields",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(
						make_shared<FakeScores>(),
						make_shared<FakeOptions>()
					),
					make_shared<HttpRequest>("")
				),
				R"("platform":"null")",
				R"("cpus":0)",
				R"("total_mem":)",
				R"("memory":)",
				R"("load":)",
				R"("threads":)",
				R"("protocol":)",
				R"("score":{)",
				// Score content
				R"("invoice":)"
			)
		)
	)
{
}
