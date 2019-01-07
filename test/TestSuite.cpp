// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestSuite.h"
#include <2out/Result.h>

using namespace std;

TestSuite::TestSuite(const shared_ptr<const oout::Test> &test)
	: tests(test)
{
}

unique_ptr<const oout::Result> TestSuite::result() const
{
	return tests->result();
}
