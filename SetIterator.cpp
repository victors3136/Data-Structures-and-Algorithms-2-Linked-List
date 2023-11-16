#include "SetIterator.h"
#include "Set.h"
#include <stdexcept>

[[maybe_unused]] SetIterator::SetIterator(const Set& m) : set(m){ current = set.start;}


void SetIterator::first() {
	current = set.start;
}
void SetIterator::last() {
	current = set.end;
}

void SetIterator::next() {
	if(!valid()){
		throw std::runtime_error("Error: Invalid iterator position.");
	}
	current = current->getNext();
}

void SetIterator::jumpBackward(int steps){
	if(!valid()){
		throw std::runtime_error("Error: Invalid iterator position");
	}
	if(steps <= 0){
		throw std::runtime_error("Error: Invalid nr of steps");
	}

	while(steps && current != nullptr){
		current = current->getBefore();
		steps--;
	}
	/// if steps > 0 then current will be nullptr, so the iterator will be invalid
}

TElem SetIterator::getCurrent()
{
	if (!valid()){
		throw std::runtime_error("Error: Invalid iterator position.");
	}
	return current->getData();
}

bool SetIterator::valid() const {
	return current != nullptr;
}



