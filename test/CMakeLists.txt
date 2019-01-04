CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(zond-test)

ADD_EXECUTABLE(
	zond-test
	test.cpp
	CommandlineOptionsTest.cpp
	ContentResponseTest.cpp
	CriterionRepr.cpp
	EntryRepr.cpp
	EqualCriterionTest.cpp
	FakeEntry.cpp
	FakeScore.cpp
	FakeScores.cpp
	HttpHeaderTest.cpp
	MethodCriterionTest.cpp
	ParamResponseTest.cpp
	SelectedEntryTest.cpp
	StrongestScoresTest.cpp
	TestSuite.cpp
	ZoldProtocolEntryTest.cpp
)

TARGET_LINK_LIBRARIES(
	zond-test
	2out
	zond-http
)

ADD_CUSTOM_COMMAND(
	TARGET zond-test
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/test-results/2out
)

ADD_TEST(
	NAME zond-test
	COMMAND sh -c "${CMAKE_BINARY_DIR}/bin/zond-test > ${CMAKE_BINARY_DIR}/test-results/2out/results.xml"
)
