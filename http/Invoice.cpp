// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Invoice.h"
#include <random>
#include "Options.h"
#include "OptionInt.h"

using namespace std;

Invoice::Invoice(const shared_ptr<const Options> &options)
	: pfx(make_prefix(options)), wlt(options->value("wallet"))
{
}

string Invoice::prefix() const
{
	return pfx;
}

string Invoice::wallet() const
{
	return wlt;
}

string Invoice::str() const
{
	return pfx + "@" + wlt;
}

string Invoice::make_prefix(const shared_ptr<const Options> &options) const
{
	const auto pubkey = options->value("pubkey");
	const int length = OptionInt(options, "prefix-length");
	const string enabled =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789";

	random_device rd;
	default_random_engine re(rd());
	uniform_int_distribution<size_t> rn(0, pubkey.size() - length);

	string prefix;
	do {
		prefix = pubkey.substr(rn(re), length);
	} while (prefix.find_first_not_of(enabled) != string::npos);

	return prefix;
}
