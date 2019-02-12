// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FakeOptions.h"
#include "../http/MultipleSourcesOptions.h"

using namespace std;

FakeOptions::FakeOptions(const std::shared_ptr<const Options> &options)
	: options(
		make_shared<MultipleSourcesOptions>(
			options,
			make_shared<PredefinedOptions>(
				"host", "zold.io",
				"mining-threads", "1",
				"port", "4096",
				"prefix-length", "8",
				"protocol", "2",
				"pubkey", string(1024, 'A'),
				"server-repo", "dronmdf/zond",
				"server-version", "0.0.1",
				"strength", "3",
				"wallet", "1234567812345678"
			)
		)
	)
{
}

FakeOptions::FakeOptions()
	: FakeOptions(make_shared<PredefinedOptions>())
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
