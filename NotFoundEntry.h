// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <string>

// @todo #45 Create Enrty interface
//  and inherite NotFoundEntry from Entry.
//  Entry::process should give HttpRequest as arg
//  and return HttpResponse
class NotFoundEntry final {
public:
	std::string process() const;
};
