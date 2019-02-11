// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FakeOptions.h"
#include "../http/PredefinedOptions.h"

using namespace std;

FakeOptions::FakeOptions()
	: options(
		make_shared<PredefinedOptions>(
			"mining-threads", "1",
			"protocol", "2",
			"strength", "8"
		)
	)
{
}

string FakeOptions::value(const string &name) const
{
	return options->value(name);
}

bool FakeOptions::enabled(const string &name) const
{
	return options->enabled(name);
}
