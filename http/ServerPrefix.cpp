// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ServerPrefix.h"
#include "OptionInt.h"
#include "Options.h"

using namespace std;

ServerPrefix::ServerPrefix(const shared_ptr<const Options> &options)
	: _time(chrono::system_clock::now()),
	  _host(options->value("host")),
	  _port(OptionInt(options, "port")),
	  _invoice(options)
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
	return _invoice.str();
}

string ServerPrefix::prefix() const
{
	return _invoice.prefix();
}

string ServerPrefix::wallet() const
{
	return _invoice.wallet();
}
