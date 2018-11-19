// Copyright (c) 2018 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <2out/CountError.h>
#include <2out/CountFailure.h>
#include <2out/JUnitXmlReport.h>
#include <2out/Result.h>
#include <2out/TestEqual.h>

using namespace std;
using namespace oout;

int main(int, char **)
{
	const shared_ptr<const Result> result = TestEqual(
		"zond", "zond"
	).result();

	cout << JUnitXmlReport(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}