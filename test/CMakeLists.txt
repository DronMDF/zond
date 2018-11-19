CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_EXECUTABLE(
	test
	test.cpp
)

TARGET_LINK_LIBRARIES(
	test
	2out
)

ADD_CUSTOM_COMMAND(
	TARGET test
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/test-results/2out
)

ADD_TEST(
	NAME test
	COMMAND sh -c "${CMAKE_BINARY_DIR}/bin/test > ${CMAKE_BINARY_DIR}/test-results/2out/results.xml"
)
