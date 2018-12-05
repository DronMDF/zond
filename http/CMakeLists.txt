CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(zond-http)

ADD_COMPILE_OPTIONS(-std=c++14 -O2 -fomit-frame-pointer -g0
	-Wall -Wextra -Wpedantic -Werror
	-Wno-non-virtual-dtor)

ADD_LIBRARY(
	zond-http
	GetVersionEntry.cpp
	HttpHeader.cpp
	HttpRequest.cpp
	NotFoundEntry.cpp
	SelectedEntry.cpp
	StringHttpResponse.cpp
)
