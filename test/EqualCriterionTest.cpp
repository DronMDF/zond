// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EqualCriterionTest.h"
#include <2out/Representation.h>
#include <2out/Result.h>
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include <2out/TestEqual.h>
#include "../http/EqualCriterion.h"
#include "../http/HttpRequest.h"

using namespace std;
using namespace oout;

class CriterionRepr final : public Representation {
public:
	CriterionRepr(
		const shared_ptr<const Criterion> &criterion,
		const shared_ptr<const HttpRequest> &request
	) : criterion(criterion), request(request)
	{
	}

	string asString() const override
	{
		return criterion->suitable(request) ? "suitable" : "unsuitable";
	}
private:
	const shared_ptr<const Criterion> criterion;
	const shared_ptr<const HttpRequest> request;
};

EqualCriterionTest::EqualCriterionTest()
	: tests(
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

unique_ptr<const Result> EqualCriterionTest::result() const
{
	return tests.result();
}
