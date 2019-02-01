// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EqualCriterionTest.h"
#include "../http/EqualCriterion.h"
#include "../http/HttpRequest.h"
#include "CriterionRepr.h"

using namespace std;
using namespace oout;

EqualCriterionTest::EqualCriterionTest()
	: TestSuite(
		make_shared<TestNamed>(
			"EqualCriterion consider the request as suitable by uri",
			make_shared<TestEqual>(
				make_shared<CriterionRepr>(
					make_shared<EqualCriterion>("/version"),
					make_shared<HttpRequest>(
						"GET /version HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"suitable"
			)
		),
		make_shared<TestNamed>(
			"EqualCriterion consider the request as unsuitable by uri",
			make_shared<TestEqual>(
				make_shared<CriterionRepr>(
					make_shared<EqualCriterion>("/version"),
					make_shared<HttpRequest>(
						"GET /something HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"unsuitable"
			)
		)
	)
{
}
