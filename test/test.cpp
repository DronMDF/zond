// Copyright (c) 2018-2019 Andrey Valyaev
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <2out/CountError.h>
#include <2out/CountFailure.h>
#include <2out/JUnitXmlReport.h>
#include <2out/Result.h>
#include <2out/TestSuite.h>
#include <2out/TestTimed.h>
#include "ActiveScoresTest.h"
#include "CommandlineOptionsTest.h"
#include "ContentResponseTest.h"
#include "EqualCriterionTest.h"
#include "GetInfoEntryTest.h"
#include "GetRemotesEntryTest.h"
#include "GetVersionEntryTest.h"
#include "HttpHeaderTest.h"
#include "MethodCriterionTest.h"
#include "MultipleSourcesOptionsTest.h"
#include "ParamResponseTest.h"
#include "ScoreJsonTest.h"
#include "ScoreValidTest.h"
#include "SelectedEntryTest.h"
#include "StringScoreTest.h"
#include "StrongestScoresTest.h"
#include "ZoldProtocolEntryTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const shared_ptr<const Result> result = TestTimed(
		make_shared<oout::TestSuite>(
			make_shared<ActiveScoresTest>(),
			make_shared<CommandlineOptionsTest>(),
			make_shared<ContentResponseTest>(),
			make_shared<EqualCriterionTest>(),
			make_shared<GetInfoEntryTest>(),
			make_shared<GetRemotesEntryTest>(),
			make_shared<GetVersionEntryTest>(),
			make_shared<HttpHeaderTest>(),
			make_shared<MethodCriterionTest>(),
			make_shared<MultipleSourcesOptionsTest>(),
			make_shared<ParamResponseTest>(),
			make_shared<ScoreJsonTest>(),
			make_shared<ScoreValidTest>(),
			make_shared<SelectedEntryTest>(),
			make_shared<StringScoreTest>(),
			make_shared<StrongestScoresTest>(),
			make_shared<ZoldProtocolEntryTest>()
		)
	).result();

	cout << JUnitXmlReport(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
