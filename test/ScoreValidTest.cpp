// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ScoreValidTest.h"
#include <2out/Representation.h>
#include <2out/TestNamed.h>
#include <2out/TestEqual.h>
#include "../http/PredefinedOptions.h"
#include "../http/ScoreValid.h"
#include "../http/ServerScore.h"

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
					make_shared<ServerScore>(
						make_shared<PredefinedOptions>(
							"host", "host",
							"port", "222",
							"pubkey", "publickey",
							"wallet", "1234567812345678"
						)
					),
					make_shared<PredefinedOptions>(
						"score-livetime", "600",
						"strength", "8"
					)
				),
				"valid"
			)
		)
	)
{
}

