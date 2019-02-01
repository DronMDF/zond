// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreJsonTest.h"
#include "../http/PredefinedOptions.h"
#include "../http/ScoreJson.h"
#include "FakeScore.h"

using namespace oout;
using namespace std;

class ScoreJsonRepr final : public Representation {
public:
	ScoreJsonRepr(
		const shared_ptr<const Score> &score,
		const shared_ptr<const Options> &options
	) : score(score), options(options)
	{
	}

	string asString() const override
	{
		const nlohmann::json json = ScoreJson(score, options);
		return json.dump();
	}
private:
	const shared_ptr<const Score> score;
	const shared_ptr<const Options> options;
};

ScoreJsonTest::ScoreJsonTest()
	: TestSuite(
		make_shared<TestNamed>(
			"ScoreJson should contain strength",
			make_shared<TestContainText>(
				make_shared<ScoreJsonRepr>(
					make_shared<FakeScore>(0),
					make_shared<PredefinedOptions>(
						"strength", "8"
					)
				),
				R"("strength":8)"
			)
		),
		make_shared<TestNamed>(
			"ScoreJson should contain expired flag",
			make_shared<TestContainText>(
				make_shared<ScoreJsonRepr>(
					make_shared<FakeScore>(0),
					make_shared<PredefinedOptions>(
						"strength", "8"
					)
				),
				R"("expired":false)"
			)
		),
		make_shared<TestNamed>(
			"ScoreJson should contain value",
			make_shared<TestContainText>(
				make_shared<ScoreJsonRepr>(
					make_shared<FakeScore>(2),
					make_shared<PredefinedOptions>(
						"strength", "3"
					)
				),
				R"("value":2)"
			)
		)
	)
{
}
