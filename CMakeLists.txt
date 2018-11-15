CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(zond)

INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

ADD_COMPILE_OPTIONS(-std=c++14 -O2 -fomit-frame-pointer -g0
	-Wall -Wextra -Weffc++ -Wpedantic -Werror
	-Wno-non-virtual-dtor)

ADD_EXECUTABLE(zond
	main.cpp
)

ADD_CUSTOM_TARGET(
	style
	COMMAND ${CMAKE_SOURCE_DIR}/style.sh
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
# @todo #1 add unittest
