CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(zond)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

ADD_EXECUTABLE(zond
	main.cpp
)

# @todo #1 add style check
# @todo #1 add unittest
