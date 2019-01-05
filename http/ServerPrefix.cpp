// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ServerPrefix.h"
#include "Options.h"

using namespace std;

ServerPrefix::ServerPrefix(const shared_ptr<const Options> &options)
	: _time(chrono::system_clock::now()),
	  _host(options->value("host")),
	  _port(atoi(options->value("port").c_str())),
	  // @todo #136 Create invoice class
	  _invoice(options->value("pubkey").substr(0, 8) + "@" + options->value("wallet"))
{
}

chrono::system_clock::time_point ServerPrefix::time() const
{
	return _time;
}

string ServerPrefix::host() const
{
	return _host;
}

int ServerPrefix::port() const
{
	return _port;
}

string ServerPrefix::invoice() const
{
	return _invoice;
}
