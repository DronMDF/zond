// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StringPrefix.h"
#include <iomanip>
#include <sstream>

using namespace std;

StringPrefix::StringPrefix(const string &prefix)
	: pfx(prefix)
{
}

chrono::system_clock::time_point StringPrefix::time() const
{
	tm tm;
	if (strptime(pfx.c_str(), "%FT%T%z", &tm) == nullptr) {
		throw runtime_error("Wrong score time format");
	}
	return chrono::system_clock::from_time_t(timegm(&tm));
}

string StringPrefix::host() const
{
	istringstream in(pfx);
	string time, host;
	in >> time >> host;
	return host;
}

int StringPrefix::port() const
{
	istringstream in(pfx);
	string time, host;
	int port;
	in >> time >> host >> port;
	return port;
}

string StringPrefix::invoice() const
{
	istringstream in(pfx);
	string time, host, port, invoice;
	in >> time >> host >> port >> invoice;
	return invoice;
}
