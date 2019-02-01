// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MultipleSourcesOptionsTest.h"
#include "../http/MultipleSourcesOptions.h"
#include "../http/PredefinedOptions.h"

using namespace oout;
using namespace std;

class OptionsValueRepr final : public Representation {
public:
	OptionsValueRepr(const shared_ptr<const Options> &options, const string &name)
		: options(options), name(name)
	{
	}

	string asString() const override
	{
		return options->value(name);
	}
private:
	const shared_ptr<const Options> options;
	const string name;
};

MultipleSourcesOptionsTest::MultipleSourcesOptionsTest()
	: TestSuite(
		make_shared<TestNamed>(
			"MultipleSourcesOptions return first value if exists",
			make_shared<TestEqual>(
				make_shared<OptionsValueRepr>(
					make_shared<MultipleSourcesOptions>(
						make_shared<PredefinedOptions>(
							"server-version", "1.1.1"
						),
						make_shared<PredefinedOptions>(
							"server-version", "0.0.0"
						)
					),
					"server-version"
				),
				"1.1.1"
			)
		),
		make_shared<TestNamed>(
			"MultipleSourcesOptions return last value if not exists in first",
			make_shared<TestEqual>(
				make_shared<OptionsValueRepr>(
					make_shared<MultipleSourcesOptions>(
						make_shared<PredefinedOptions>(
						),
						make_shared<PredefinedOptions>(
							"server-version", "0.0.0"
						)
					),
					"server-version"
				),
				"0.0.0"
			)
		)
	)
{
}

