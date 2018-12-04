CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_EXECUTABLE(
	test-runner
	test.cpp
	HttpHeaderTest.cpp
	SelectedEntryTest.cpp
	# @todo #39 Filelist are copy pasted
	#  this cause double compilation
	../GetVersionEntry.cpp
	../HttpHeader.cpp
	../HttpRequest.cpp
	../NotFoundEntry.cpp
	../SelectedEntry.cpp
	../StringHttpResponse.cpp
)

TARGET_LINK_LIBRARIES(
	test-runner
	2out
)

ADD_CUSTOM_COMMAND(
	TARGET test-runner
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/test-results/2out
)

ADD_TEST(
	NAME test-runner
	COMMAND sh -c "${CMAKE_BINARY_DIR}/bin/test-runner > ${CMAKE_BINARY_DIR}/test-results/2out/results.xml"
)
