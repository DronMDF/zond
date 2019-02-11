// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "PrefixString.h"
#include <iomanip>
#include <sstream>
#include "OptionInt.h"
#include "Prefix.h"

using namespace std;

PrefixString::PrefixString(
	const shared_ptr<const Prefix> &prefix,
	const shared_ptr<const Options> &options
) : prefix(prefix), options(options)
{
}

string PrefixString::value() const
{
	const auto t = chrono::system_clock::to_time_t(prefix->time());
	ostringstream out;
	out << OptionInt(options, "strength") << " "
		<< hex << t << " "
		<< prefix->host() << " "
		<< prefix->port() << " "
		<< prefix->prefix() << " "
		<< prefix->wallet();
	return out.str();
}
