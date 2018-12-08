
// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MethodCriterionTest.h"
#include <2out/Result.h>
#include <2out/TestNamed.h>
#include <2out/TestEqual.h>
#include <2out/TestSkipped.h>
#include "../http/MethodCriterion.h"
#include "../http/HttpRequest.h"
#include "CriterionRepr.h"

using namespace std;
using namespace oout;

MethodCriterionTest::MethodCriterionTest()
	: tests(
		make_shared<TestNamed>(
			"MethodCriterion consider the request as suitable by method",
			// @todo #74 Unskip MethodCriterion success test
			//  after HttpRequest return method
			make_shared<TestSkipped>(
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
		)
	)
{
}

unique_ptr<const Result> MethodCriterionTest::result() const
{
	return tests.result();
}