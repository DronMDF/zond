// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MethodCriterionTest.h"
#include "../http/EqualCriterion.h"
#include "../http/HttpRequest.h"
#include "../http/MethodCriterion.h"
#include "CriterionRepr.h"

using namespace std;
using namespace oout;

MethodCriterionTest::MethodCriterionTest()
	: TestSuite(
		make_shared<TestNamed>(
			"MethodCriterion consider the request as suitable by method",
			make_shared<TestEqual>(
				make_shared<CriterionRepr>(
					make_shared<MethodCriterion>("GET"),
					make_shared<HttpRequest>(
						"GET /version HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"suitable"
			)
		),
		make_shared<TestNamed>(
			"MethodCriterion consider the request as unsuitable by method",
			make_shared<TestEqual>(
				make_shared<CriterionRepr>(
					make_shared<MethodCriterion>("HEAD"),
					make_shared<HttpRequest>(
						"GET /something HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"unsuitable"
			)
		),
		make_shared<TestNamed>(
			"MethodCriterion should wrap other criterion",
			make_shared<TestEqual>(
				make_shared<CriterionRepr>(
					make_shared<MethodCriterion>(
						"GET",
						make_shared<EqualCriterion>("/uri")
					),
					make_shared<HttpRequest>(
						"GET /uri HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"suitable"
			)
		),
		make_shared<TestNamed>(
			"MethodCriterion should wrap other criterion and fail",
			make_shared<TestEqual>(
				make_shared<CriterionRepr>(
					make_shared<MethodCriterion>(
						"GET",
						make_shared<EqualCriterion>("/something")
					),
					make_shared<HttpRequest>(
						"GET /uri HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"unsuitable"
			)
		)
	)
{
}
