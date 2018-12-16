// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <2out/Test.h>
#include <2out/TestSuite.h>

class ZoldProtocolEntryTest final : public oout::Test {
public:
	ZoldProtocolEntryTest();
	// @todo #105 need share result method
	//  This is not acceptable for 2out library,
	//  but acceptable for project, tested with 2out
	std::unique_ptr<const oout::Result> result() const override;
private:
	const oout::TestSuite tests;
};
