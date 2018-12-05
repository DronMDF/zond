// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "HttpHeaderTest.h"
#include <2out/Representation.h>
#include <2out/Result.h>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include "../http/HttpHeader.h"

using namespace std;
using namespace oout;

class HttpHeaderFieldRepr final : public Representation {
public:
	HttpHeaderFieldRepr(
		const shared_ptr<const HttpHeader> &header,
		const string &field,
		const string &default_value = ""
	) : header(header), field(field), default_value(default_value)
	{
	}

	string asString() const override
	{
		return header->getField(field, default_value);
	}
private:
	const shared_ptr<const HttpHeader> header;
	const string field;
	const string default_value;
};

HttpHeaderTest::HttpHeaderTest()
	: tests(
		make_shared<const TestNamed>(
			"Capital-Letter-Field",
			make_shared<const TestEqual>(
				make_shared<const HttpHeaderFieldRepr>(
					make_shared<const HttpHeader>(
						"HTTP/1.1 404 Not Found\r\n"
						"Content-Length: 12345\r\n"
						"\r\n"
					),
					"Content-Length"
				),
				"12345"
			)
		),
		make_shared<const TestNamed>(
			"low-letter-field",
			make_shared<const TestEqual>(
				make_shared<const HttpHeaderFieldRepr>(
					make_shared<const HttpHeader>(
						"HTTP/1.1 404 Not Found\r\n"
						"content-length: 777\r\n"
						"\r\n"
					),
					"Content-Length"
				),
				"777"
			)
		),
		make_shared<const TestNamed>(
			"default-value",
			make_shared<const TestEqual>(
				make_shared<const HttpHeaderFieldRepr>(
					make_shared<const HttpHeader>(
						"HTTP/1.1 404 Not Found\r\n"
						"\r\n"
					),
					"Content-Length",
					"0"
				),
				"0"
			)
		)
	)
{
}

unique_ptr<const Result> HttpHeaderTest::result() const
{
	return tests.result();
}
