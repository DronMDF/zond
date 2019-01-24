// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "PrefixJson.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include "Prefix.h"

using namespace std;

PrefixJson::PrefixJson(const shared_ptr<const Prefix> &prefix)
	: prefix(prefix)
{
}

PrefixJson::operator nlohmann::json() const
{
	// @todo #182 Convert time to string is typical operation.
	//  copypaste ftom PrefixString
	const auto t = chrono::system_clock::to_time_t(prefix->time());
	const auto tm = *gmtime(&t);
	ostringstream out;
	out << put_time(&tm, "%FT%TZ");
	return {
		{"time", out.str()},
		{"host", prefix->host()},
		{"port", prefix->port()},
		{"invoice", prefix->invoice()}
	};
}
