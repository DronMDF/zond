// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ZoldProtocolEntryTest.h"
#include <2out/Result.h>
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include "../http/HttpHeader.h"
#include "../http/HttpRequest.h"
#include "../http/Response.h"
#include "../http/Score.h"
#include "../http/Scores.h"
#include "../http/ZoldProtocolEntry.h"
#include "EntryRepr.h"
#include "FakeEntry.h"

using namespace std;
using namespace oout;

class FakeScore final : public Score {
public:
	shared_ptr<const Prefix> prefix() const override
	{
		return {};
	}

	list<string> suffixes() const override
	{
		return {};
	}
};

class FakeScores final : public Scores {
public:
	shared_ptr<const Score> front() const override
	{
		return make_shared<FakeScore>();
	}
};

ZoldProtocolEntryTest::ZoldProtocolEntryTest()
	: TestSuite(
		make_shared<TestNamed>(
			"ZoldProtocolEntry should add Zold-Score into reply",
			make_shared<TestContainText>(
				make_shared<EntryRepr>(
					make_shared<ZoldProtocolEntry>(
						make_shared<FakeEntry>(
							"HTTP/1.1 200 Ok\r\n"
							"\r\n"
						),
						make_shared<FakeScores>()
					),
					make_shared<HttpRequest>("")
				),
				"Zold-Score: "
			)
		)
	)
{
}
