CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(zond-miner)

FIND_PACKAGE(Threads)
FIND_PACKAGE(OpenSSL REQUIRED)

#INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()

ADD_COMPILE_OPTIONS(
	-std=c++14 -O2 -fomit-frame-pointer -g0
	-Wall -Wextra -Wpedantic -Werror
	-Wno-non-virtual-dtor)

ADD_EXECUTABLE(
	zond-miner
	main.cpp
)

TARGET_LINK_LIBRARIES(
	zond-miner
	zond-http
	${CMAKE_THREAD_LIBS_INIT}
	${OPENSSL_LIBRARIES}
)
