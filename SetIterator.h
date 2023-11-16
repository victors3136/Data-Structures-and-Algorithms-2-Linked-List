#pragma once
#include "Set.h"

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	DLLNode<TElem>* current;

	[[maybe_unused]] explicit SetIterator(const Set& s);
	/// \time Theta(1)
	/// \space Theta(1)
	/// \errors throws no custom errors

public:
	void first();
	/// \time Theta(1)
	/// \space Theta(1)
	/// \errors throws no custom errors
	void last();
	/// \Time Theta(1)
	/// \Space Theta(1)
	/// \Errors throws no custom errors

	void next();
	/// \time Theta(1)
	/// \space Theta(1)
	/// \errors throws runtime error if the iterator is invalid
	void jumpBackward(int steps);
	/// \Time O(steps)
	/// \Space Theta(1)
	/// \Params steps:= how many steps to jump back, has to be positive integer
	/// \Errors throws runtime error if the iterator is invalid or if steps <= 0
	TElem getCurrent();
	/// \time Theta(1)
	/// \space Theta(1)
	/// \return TElem, data at position pointed to by the iterator
	/// \errors throws runtime error if the iterator is invalid

	[[nodiscard]] bool valid() const;
	/// \time Theta(1)
	/// \space Theta(1)
	/// \return true if the current pointer is not nullptr
	/// \errors throws no custom errors
};
