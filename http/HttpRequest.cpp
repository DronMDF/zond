// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "HttpRequest.h"
#include "HttpHeader.h"

using namespace std;

HttpRequest::HttpRequest(const shared_ptr<const HttpHeader> &header, const string &body)
	: header(header), body(body)
{
}

HttpRequest::HttpRequest(const string &header, const string &body)
	: HttpRequest(make_shared<HttpHeader>(header), body)
{
}

HttpRequest::HttpRequest(const string &header)
	: HttpRequest(make_shared<HttpHeader>(header), {})
{
}

string HttpRequest::method() const
{
	return header->method();
}

string HttpRequest::uri() const
{
	return header->uri();
}
