// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SelectedEntryTest.h"
#include <2out/Representation.h>
#include <2out/Result.h>
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include <2out/TestSkipped.h>
#include "../GetVersionEntry.h"
#include "../HttpHeader.h"
#include "../HttpRequest.h"
#include "../HttpResponse.h"
#include "../NotFoundEntry.h"
#include "../SelectedEntry.h"

using namespace std;
using namespace oout;

class EntryRepr final : public Representation {
public:
	EntryRepr(
		const shared_ptr<const Entry> &entry,
		const shared_ptr<const HttpRequest> &request
	) : entry(entry), request(request)
	{
	}

	string asString() const override
	{
		return entry->process(request)->asString();
	}
private:
	const shared_ptr<const Entry> entry;
	const shared_ptr<const HttpRequest> request;
};

SelectedEntryTest::SelectedEntryTest()
	: tests(
		make_shared<TestNamed>(
			"Select first entry",
			make_shared<TestSkipped>(
				make_shared<TestContainText>(
					make_shared<const EntryRepr>(
						make_shared<const SelectedEntry>(
							make_shared<GetVersionEntry>(),
							make_shared<NotFoundEntry>()
						),
						// @todo #55 Construct HttpRequest with two string
						make_shared<HttpRequest>(
							make_shared<HttpHeader>(
								"GET /version HTTP/1.1\r\n"
								"\r\n"
							),
							""
						)
					),
					"200 OK"
				)
			)
		),
		make_shared<const TestNamed>(
			"Select last entry",
			make_shared<const TestContainText>(
				make_shared<const EntryRepr>(
					make_shared<const SelectedEntry>(
						make_shared<GetVersionEntry>(),
						make_shared<NotFoundEntry>()
					),
					make_shared<HttpRequest>(
						make_shared<HttpHeader>(
							"GET /something HTTP/1.1\r\n"
							"\r\n"
						),
						""
					)
				),
				"404 Not Found"
			)
		)
	)
{
}

unique_ptr<const Result> SelectedEntryTest::result() const
{
	return tests.result();
}
