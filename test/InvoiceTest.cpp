// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "InvoiceTest.h"
#include "../http/Invoice.h"
#include "FakeOptions.h"

using namespace oout;
using namespace std;

InvoiceTest::InvoiceTest()
	: TestSuite(
		make_shared<TestNamed>(
			"Invoice should select prefix from pubkey",
			make_shared<TestContainText>(
				"qwertyuiopasdfghjklzxcvbnm",
				make_shared<ReprCallable>(
					bind(&Invoice::prefix, Invoice(
						make_shared<FakeOptions>(
							"pubkey", "qwertyuiopasdfghjklzxcvbnm",
							"prefix-length", "8"
						)
					))
				)
			)
		),
		make_shared<TestNamed>(
			"Invoice should select prefix randomly from pubkey",
			make_shared<TestEqual>(
				make_shared<ReprCallable>(
					bind(&Invoice::prefix, Invoice(
						make_shared<FakeOptions>(
							"pubkey", "a" + string(4096, 'b'),
							"prefix-length", "8"
						)
					))
				),
				"bbbbbbbb"
			)
		)
	)
{
}

