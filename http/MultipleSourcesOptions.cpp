// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MultipleSourcesOptions.h"

using namespace std;

MultipleSourcesOptions::MultipleSourcesOptions(
	const shared_ptr<const Options> &options,
	const shared_ptr<const Options> &fallback
) : options(options), fallback(fallback)
{
}

string MultipleSourcesOptions::value(const string &name) const
{
	try {
		return options->value(name);
	} catch (const exception &) {
		return fallback->value(name);
	}
}

bool MultipleSourcesOptions::enabled(const string &name) const
{
	try {
		// @todo #117 Options::enabled should raise except if flag is not defined
		return options->enabled(name);
	} catch (const exception &) {
		return fallback->enabled(name);
	}
}
