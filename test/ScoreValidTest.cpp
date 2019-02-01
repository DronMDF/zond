// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreValidTest.h"
#include "../http/PredefinedOptions.h"
#include "../http/ScoreValid.h"
#include "../http/StringScore.h"
#include "../http/SuffixScore.h"
#include "FakeScore.h"

using namespace oout;
using namespace std;

class ScoreValidRepr final : public Representation {
public:
	ScoreValidRepr(
		const shared_ptr<const Score> &score,
		const shared_ptr<const Options> &options
	) : score(score), options(options)
	{
	}

	string asString() const override
	{
		return ScoreValid(score, options) ? "valid" : "invalid";
	}
private:
	const shared_ptr<const Score> score;
	const shared_ptr<const Options> options;
};

ScoreValidTest::ScoreValidTest()
	: TestSuite(
		make_shared<TestNamed>(
			"ScoreValid is valid for new score without suffixes",
			make_shared<TestEqual>(
				make_shared<ScoreValidRepr>(
					make_shared<FakeScore>(0),
					make_shared<PredefinedOptions>(
						"score-livetime", "600",
						"strength", "8"
					)
				),
				"valid"
			)
		),
		make_shared<TestNamed>(
			"ScoreValid is invalid for outdated Score",
			make_shared<TestEqual>(
				make_shared<ScoreValidRepr>(
					make_shared<StringScore>(
						"2019-01-19T17:20:53Z b2.zold.io "
						"4096 DpTOG8hC@912ecc24b32dbe74"
					),
					make_shared<PredefinedOptions>(
						"score-livetime", "600",
						"strength", "8"
					)
				),
				"invalid"
			)
		),
		make_shared<TestNamed>(
			"ScoreValid is valid for score with walid suffixes",
			make_shared<TestEqual>(
				make_shared<ScoreValidRepr>(
					make_shared<FakeScore>(2),
					make_shared<PredefinedOptions>(
						"score-livetime", "600",
						"strength", "3"
					)
				),
				"valid"
			)
		),
		make_shared<TestNamed>(
			"ScoreValid is invalid for score with wrong suffix in middle",
			make_shared<TestEqual>(
				make_shared<ScoreValidRepr>(
					make_shared<SuffixScore>(
						make_shared<SuffixScore>(
							make_shared<FakeScore>(0),
							"fakesuffix"
						),
						make_shared<PredefinedOptions>(
							"strength", "3"
						)
					),
					make_shared<PredefinedOptions>(
						"score-livetime", "600",
						"strength", "3"
					)
				),
				"invalid"
			)
		)
	)
{
}

