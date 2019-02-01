// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CommandlineOptionsTest.h"
#include "../http/CommandlineOptions.h"

using namespace oout;
using namespace std;

class FlagRepr final : public Representation {
public:
	FlagRepr(const shared_ptr<const Options> &options, const string &flag)
		: options(options), flag(flag)
	{
	}

	string asString() const override
	{
		return options->enabled(flag) ? "enabled" : "disabled";
	}
private:
	const shared_ptr<const Options> options;
	const string flag;
};

CommandlineOptionsTest::CommandlineOptionsTest()
	: TestSuite(
		make_shared<TestNamed>(
			"CommandlineOptions flag disable by default",
			make_shared<TestEqual>(
				make_shared<FlagRepr>(
					make_shared<CommandlineOptions>(list<string>{}),
					"score-in-reply"
				),
				"disabled"
			)
		),
		make_shared<TestNamed>(
			"CommandlineOptions flag enabled by explicit",
			make_shared<TestEqual>(
				make_shared<FlagRepr>(
					make_shared<CommandlineOptions>(
						list<string>{"--enable-score-in-reply"}
					),
					"score-in-reply"
				),
				"enabled"
			)
		)
	)
{
}
