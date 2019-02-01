// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/2out.h>

class TestSuite : public oout::Test {
public:
	// Primary ctor
	explicit TestSuite(const std::shared_ptr<const oout::Test> &test);

	// Secondary ctor with multiple tests
	template<typename... T>
	TestSuite(
		const std::shared_ptr<const oout::Test> &test1,
		const std::shared_ptr<const oout::Test> &test2,
		const std::shared_ptr<T> & ... tests
	) : TestSuite(std::make_shared<const oout::TestSuite>(test1, test2, tests...))
	{
	}

	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::shared_ptr<const oout::Test> tests;
};
