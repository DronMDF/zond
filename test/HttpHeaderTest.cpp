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

class HttpHeaderUriRepr final : public Representation {
public:
	explicit HttpHeaderUriRepr(const shared_ptr<const HttpHeader> &header)
		: header(header)
	{
	}

	string asString() const override
	{
		return header->uri();
	}
private:
	const shared_ptr<const HttpHeader> header;
};

class HttpHeaderMethodRepr final : public Representation {
public:
	explicit HttpHeaderMethodRepr(const shared_ptr<const HttpHeader> &header)
		: header(header)
	{
	}

	string asString() const override
	{
		return header->method();
	}
private:
	const shared_ptr<const HttpHeader> header;
};

HttpHeaderTest::HttpHeaderTest()
	: tests(
		make_shared<TestNamed>(
			"HttpHeader get Capital-Letter style field value",
			make_shared<TestEqual>(
				make_shared<HttpHeaderFieldRepr>(
					make_shared<HttpHeader>(
						"GET /version HTTP/1.1\r\n"
						"Content-Length: 12345\r\n"
						"\r\n"
					),
					"Content-Length"
				),
				"12345"
			)
		),
		make_shared<TestNamed>(
			"HttpHeader get low-letter style field value",
			make_shared<TestEqual>(
				make_shared<HttpHeaderFieldRepr>(
					make_shared<HttpHeader>(
						"GET /version HTTP/1.0\r\n"
						"content-length: 777\r\n"
						"\r\n"
					),
					"Content-Length"
				),
				"777"
			)
		),
		make_shared<TestNamed>(
			"HttpHeader return refault field value if it not exist",
			make_shared<TestEqual>(
				make_shared<HttpHeaderFieldRepr>(
					make_shared<HttpHeader>(
						"GET /version HTTP/1.1\r\n"
						"\r\n"
					),
					"Content-Length",
					"0"
				),
				"0"
			)
		),
		make_shared<TestNamed>(
			"HttpHeader get uri in trivial case",
			make_shared<TestEqual>(
				make_shared<HttpHeaderUriRepr>(
					make_shared<HttpHeader>(
						"GET /version HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"/version"
			)
		),
		make_shared<TestNamed>(
			"HttpHeader get method in trivial case",
			make_shared<TestEqual>(
				make_shared<HttpHeaderMethodRepr>(
					make_shared<HttpHeader>(
						"GET /version HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"GET"
			)
		)
	)
{
}

unique_ptr<const Result> HttpHeaderTest::result() const
{
	return tests.result();
}
