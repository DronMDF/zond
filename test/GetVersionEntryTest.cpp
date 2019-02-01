// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetVersionEntryTest.h"
#include "../http/GetVersionEntry.h"
#include "../http/HttpRequest.h"
#include "../http/PredefinedOptions.h"
#include "EntryRepr.h"

using namespace std;
using namespace oout;

GetVersionEntryTest::GetVersionEntryTest()
	: TestSuite(
		make_shared<TestNamed>(
			"GetVersionEntry reply contain predefined version",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<GetVersionEntry>(
						make_shared<PredefinedOptions>(
							"version", "7.6.5"
						)
					),
					make_shared<HttpRequest>("")
				),
				"Content-Length: 5\r\n",
				"\r\n\r\n7.6.5"
			)
		)
	)
{
}
