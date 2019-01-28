CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(zond)

FIND_PACKAGE(Threads)
FIND_PACKAGE(OpenSSL REQUIRED)

INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

ENABLE_TESTING()

ADD_COMPILE_OPTIONS(-std=c++14 -O2 -fomit-frame-pointer -g0
	-Wall -Wextra -Wpedantic -Werror
	-Wno-non-virtual-dtor)

ADD_EXECUTABLE(zond
	main.cpp
	Listener.cpp
	Periodic.cpp
	Session.cpp
)

TARGET_LINK_LIBRARIES(
	zond
	zond-http
	${CMAKE_THREAD_LIBS_INIT}
	${OPENSSL_LIBRARIES}
)

ADD_CUSTOM_TARGET(
	style
	COMMAND ${CMAKE_SOURCE_DIR}/style.sh
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

ADD_SUBDIRECTORY(http)
ADD_SUBDIRECTORY(miner)
ADD_SUBDIRECTORY(test)
