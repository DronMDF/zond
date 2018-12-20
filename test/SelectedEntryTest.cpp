// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SelectedEntryTest.h"
#include <2out/Result.h>
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include "../http/EqualCriterion.h"
#include "../http/HttpHeader.h"
#include "../http/HttpRequest.h"
#include "../http/Response.h"
#include "../http/MethodCriterion.h"
#include "../http/SelectedEntry.h"
#include "EntryRepr.h"
#include "FakeEntry.h"

using namespace std;
using namespace oout;

SelectedEntryTest::SelectedEntryTest()
	: TestSuite(
		make_shared<TestNamed>(
			"SelectedEntry select entry by matched uri",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<SelectedEntry>(
						make_shared<EqualCriterion>("/version"),
						make_shared<FakeEntry>("Wooho")
					),
					make_shared<HttpRequest>(
						"GET /version HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"Wooho"
			)
		),
		make_shared<TestNamed>(
			"SelectedEntry select last entry as fallback",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<SelectedEntry>(
						make_shared<EqualCriterion>("/version"),
						make_shared<FakeEntry>("Wow"),
						make_shared<FakeEntry>("Failure")
					),
					make_shared<HttpRequest>(
						"GET /something HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"Failure"
			)
		),
		make_shared<TestNamed>(
			"SelectedEntry chain entries",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<SelectedEntry>(
						make_shared<EqualCriterion>("/first"),
						make_shared<FakeEntry>("First"),
						make_shared<EqualCriterion>("/second"),
						make_shared<FakeEntry>("Second"),
						make_shared<FakeEntry>("Last")
					),
					make_shared<HttpRequest>(
						"GET /second HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"Second"
			)
		),
		make_shared<TestNamed>(
			"SelectedEntry check by method too",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<SelectedEntry>(
						make_shared<MethodCriterion>(
							"GET",
							make_shared<EqualCriterion>("/uri")
						),
						make_shared<FakeEntry>("Get"),
						make_shared<MethodCriterion>(
							"POST",
							make_shared<EqualCriterion>("/uri")
						),
						make_shared<FakeEntry>("Post")
					),
					make_shared<HttpRequest>(
						"POST /uri HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"Post"
			)
		)
	)
{
}
