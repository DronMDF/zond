CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(zond-http)

ADD_COMPILE_OPTIONS(-std=c++14 -O2 -fomit-frame-pointer -g0
	-Wall -Wextra -Wpedantic -Werror
	-Wno-non-virtual-dtor)

ADD_LIBRARY(
	zond-http
	ActiveScores.cpp
	AlwaysCriterion.cpp
	CommandlineOptions.cpp
	ContentResponse.cpp
	EqualCriterion.cpp
	GetInfoEntry.cpp
	GetRemotesEntry.cpp
	GetTasksEntry.cpp
	GetVersionEntry.cpp
	HashString.cpp
	HttpHeader.cpp
	HttpRequest.cpp
	Invoice.cpp
	OptionInt.cpp
	OptionSeconds.cpp
	MethodCriterion.cpp
	MiningPool.cpp
	MiningThread.cpp
	MultipleSourcesOptions.cpp
	NoOptions.cpp
	NotFoundEntry.cpp
	ParamResponse.cpp
	PredefinedOptions.cpp
	PrefixJson.cpp
	PrefixString.cpp
	PutScoreEntry.cpp
	RawResponse.cpp
	ScoreHashString.cpp
	ScoreIterator.cpp
	ScoreJson.cpp
	ScoreString.cpp
	ScoreValid.cpp
	SelectedEntry.cpp
	ServerPrefix.cpp
	ServerScore.cpp
	Strength.cpp
	StrongestScores.cpp
	StringPrefix.cpp
	StringScore.cpp
	SuffixScore.cpp
	ZoldProtocolEntry.cpp
)
