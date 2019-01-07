// Copyright (c) 2018-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

class Score;

class ScoreIterator final {
public:
	// Primary ctor
	ScoreIterator(
		const std::shared_ptr<const Score> &score,
		const std::shared_ptr<const ScoreIterator> &next
	);

	// Second ctors
	explicit ScoreIterator(const std::shared_ptr<const Score> &score);

	// End/Null iterator
	ScoreIterator();

	template<class ... T>
	ScoreIterator(
		const std::shared_ptr<const Score> &score,
		const std::shared_ptr<const Score> &next,
		T ... args
	) : ScoreIterator(score, std::make_shared<ScoreIterator>(next, args...))
	{
	}

	bool operator != (const ScoreIterator &other) const;
	ScoreIterator &operator ++();

	std::shared_ptr<const Score> operator *() const;

private:
	std::shared_ptr<const Score> score;
	std::shared_ptr<const ScoreIterator> next;
};
