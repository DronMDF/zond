// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetInfoEntryTest.h"
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include "../http/HttpRequest.h"
#include "../http/GetInfoEntry.h"
#include "EntryRepr.h"

using namespace std;
using namespace oout;

GetInfoEntryTest::GetInfoEntryTest()
	: TestSuite(
		make_shared<TestNamed>(
			"GetInfoEntry reply contain score field",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetInfoEntry>(),
					make_shared<HttpRequest>("")
				),
				R"("score":{)"
			)
		)
	)
{
}
