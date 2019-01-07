// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "PredefinedOptions.h"

using namespace std;

PredefinedOptions::PredefinedOptions(const map<string, string> &options)
	: options(options)
{
}

PredefinedOptions::PredefinedOptions()
	: PredefinedOptions(map<string, string>{})
{
}

string PredefinedOptions::value(const string &name) const
{
	const auto it = options.find(name);
	if (it == options.end()) {
		throw runtime_error("PredefinedOptions: Unspecified options '" + name + "'");
	}
	return it->second;
}

bool PredefinedOptions::enabled(const string &name) const
{
	const auto it = options.find(name);
	return it != options.end() && it->second == "yes";
}
