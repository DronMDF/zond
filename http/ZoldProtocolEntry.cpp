// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
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
		"X-Zold-Protocol", "2",
		// @todo #111 Set server version
		"X-Zold-Version", "0.0.0",
		"X-Zold-Repo", "DronMDF/zond",
		"X-Zold-Score", options->enabled("score-in-reply")
			? ScoreString(scores->front()).value()
			: "Under construction"
	);
}
