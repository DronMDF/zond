// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ZoldProtocolEntry.h"
#include "NoOptions.h"
#include "ParamResponse.h"
#include "Scores.h"
#include "ScoreString.h"

using namespace std;

ZoldProtocolEntry::ZoldProtocolEntry(
	const shared_ptr<const Entry> &entry,
	const shared_ptr<const Scores> &scores,
	const shared_ptr<const Options> &options
) : entry(entry), scores(scores), options(options)
{
}

ZoldProtocolEntry::ZoldProtocolEntry(
	const std::shared_ptr<const Entry> &entry,
	const std::shared_ptr<const Scores> &scores
) : ZoldProtocolEntry(entry, scores, make_shared<NoOptions>())
{
}

unique_ptr<const Response> ZoldProtocolEntry::process(
	const shared_ptr<const HttpRequest> &request
) const
{
	return make_unique<ParamResponse>(
		entry->process(request),
		"X-Zold-Protocol", options->value("protocol"),
		"X-Zold-Version", options->value("server-version"),
		"X-Zold-Repo", options->value("server-repo"),
		"X-Zold-Score", ScoreString(scores->front()).value()
	);
}
