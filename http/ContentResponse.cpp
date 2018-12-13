// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ContentResponse.h"

using namespace std;

ContentResponse::ContentResponse(const nlohmann::json &content)
	: content(content)
{
}

string ContentResponse::asString() const
{
	const auto text = body();
	return "HTTP/1.1 200 Ok\r\n"
		"Content-Type: " + type() + "\r\n"
		"Content-Length: " + to_string(text.size()) + "\r\n"
		"\r\n"
		+ text;
}

string ContentResponse::type() const
{
	return content.is_object() ? "application/json" : "text/plain";
}

string ContentResponse::body() const
{
	return content.is_object() ? content.dump() : content.get<string>();
}
