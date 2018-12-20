// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ContentResponseTest.h"
#include <2out/Result.h>
#include <2out/TestNamed.h>
#include <2out/TestContainText.h>
#include <nlohmann/json.hpp>
#include "../http/ContentResponse.h"

using namespace std;
using namespace oout;

class ResponseRepr final : public Representation {
public:
	explicit ResponseRepr(const shared_ptr<const Response> &response)
		: response(response)
	{
	}

	string asString() const override
	{
		return response->asString();
	}
private:
	const shared_ptr<const Response> response;
};

ContentResponseTest::ContentResponseTest()
	: TestSuite(
		make_shared<TestNamed>(
			"ContentResponse should fill Content-Length",
			make_shared<TestContainText>(
				make_shared<ResponseRepr>(
					make_shared<ContentResponse>("test")
				),
				"Content-Length: 4"
			)
		),
		make_shared<TestNamed>(
			"ContentResponse should fill Content-Type by default",
			make_shared<TestContainText>(
				make_shared<ResponseRepr>(
					make_shared<ContentResponse>("text")
				),
				"Content-Type: text/plain"
			)
		),
		make_shared<TestNamed>(
			"ContentResponse should have application/json type if json",
			make_shared<TestContainText>(
				make_shared<ResponseRepr>(
					make_shared<ContentResponse>(nlohmann::json::object())
				),
				"Content-Type: application/json"
			)
		)
	)
{
}
