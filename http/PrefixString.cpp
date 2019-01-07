// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "PrefixString.h"
#include <iomanip>
#include <sstream>
#include "Prefix.h"

using namespace std;

PrefixString::PrefixString(const shared_ptr<const Prefix> &prefix)
	: prefix(prefix)
{
}

string PrefixString::value() const
{
	ostringstream out;
	const auto t = chrono::system_clock::to_time_t(prefix->time());
	// @todo #126 gmtime is not threadsafe, but gmtime_r is noisely.
	//  Need to find more elegant way to convert time_potint to string
	const auto tm = *gmtime(&t);
	out << put_time(&tm, "%FT%TZ") << " "
		<< prefix->host() << " "
		<< prefix->port() << " "
		<< prefix->invoice();
	return out.str();
}
