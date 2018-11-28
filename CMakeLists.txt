CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(zond)

FIND_PACKAGE(Threads)

INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

ENABLE_TESTING()

ADD_COMPILE_OPTIONS(-std=c++14 -O2 -fomit-frame-pointer -g0
	-Wall -Wextra -Wpedantic -Werror
	-Wno-non-virtual-dtor)

ADD_EXECUTABLE(zond
	main.cpp
	HttpHeader.cpp
	NotFoundEntry.cpp
	Listener.cpp
	Session.cpp
)

TARGET_LINK_LIBRARIES(
	zond
	${CMAKE_THREAD_LIBS_INIT}
)

ADD_CUSTOM_TARGET(
	style
	COMMAND ${CMAKE_SOURCE_DIR}/style.sh
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

ADD_SUBDIRECTORY(test)
