// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "GetVersionEntryTest.h"
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
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
				"\r\n\r\n7.6.5"
				// @todo #56 After update 2out to 0.6 - use multiple matching
				//  "ContentLehgth: 5\r\n"
			)
		)
	)
{
}
