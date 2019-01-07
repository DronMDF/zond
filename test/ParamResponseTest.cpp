// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ParamResponseTest.h"
#include <2out/Representation.h>
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include "../http/ParamResponse.h"
#include "../http/RawResponse.h"

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


ParamResponseTest::ParamResponseTest()
	: TestSuite(
		make_shared<TestNamed>(
			"ParamResponse can specify multiply params",
			make_shared<TestContainText>(
				make_shared<ResponseRepr>(
					make_shared<ParamResponse>(
						make_shared<RawResponse>(
							"HTTP/1.1 200 Ok\r\n"
							"\r\n"
						),
						"first", "1",
						"second", "2"
					)
				),
				"first: 1\r\n"
				"second: 2\r\n"
				"\r\n"
			)
		)
	)
{
}
