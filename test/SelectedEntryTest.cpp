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
#include "../http/GetVersionEntry.h"
#include "../http/HttpHeader.h"
#include "../http/HttpRequest.h"
#include "../http/HttpResponse.h"
#include "../http/NotFoundEntry.h"
#include "../http/SelectedEntry.h"

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
			"SelectedEntry select entry by matched uri",
			make_shared<TestContainText>(
				make_shared<const EntryRepr>(
					make_shared<const SelectedEntry>(
						"GET",
						"/version",
						make_shared<GetVersionEntry>()
					),
					make_shared<HttpRequest>(
						"GET /version HTTP/1.1\r\n"
						"\r\n"
					)
				),
				"200 Ok"
			)
		),
		make_shared<const TestNamed>(
			"SelectedEntry select last entry as fallback",
			make_shared<const TestContainText>(
				make_shared<const EntryRepr>(
					make_shared<const SelectedEntry>(
						"GET",
						"/version",
						make_shared<GetVersionEntry>(),
						make_shared<NotFoundEntry>()
					),
					make_shared<HttpRequest>(
						"GET /something HTTP/1.1\r\n"
						"\r\n"
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
