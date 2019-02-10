// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "InvoiceTest.h"
#include "../http/Invoice.h"
#include "../http/PredefinedOptions.h"

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
						make_shared<PredefinedOptions>(
							"wallet", "cc53e22229564de6",
							"pubkey", "qwertyuiopasdfghjklzxcvbnm",
							"prefix-length", "8"
						)
					))
				)
			)
		)
	)
{
}

