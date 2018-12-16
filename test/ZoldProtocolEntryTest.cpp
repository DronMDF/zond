// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ZoldProtocolEntryTest.h"
#include <2out/Representation.h>
#include <2out/Result.h>
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include "../http/HttpHeader.h"
#include "../http/HttpRequest.h"
#include "../http/HttpResponse.h"
#include "../http/ZoldProtocolEntry.h"
#include "FakeEntry.h"

using namespace std;
using namespace oout;

// @todo #105 EntryRepr copypasted from SelectedEntryTest
//  Need to extract this class
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

ZoldProtocolEntryTest::ZoldProtocolEntryTest()
	: tests(
		make_shared<TestNamed>(
			"ZoldProtocolEntry should add Zold-Score into reply",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<ZoldProtocolEntry>(
						make_shared<FakeEntry>(
							"HTTP/1.1 200 Ok\r\n"
							"\r\n"
						)
					),
					make_shared<HttpRequest>("")
				),
				"Zold-Score: "
			)
		)
	)
{
}

unique_ptr<const Result> ZoldProtocolEntryTest::result() const
{
	return tests.result();
}
