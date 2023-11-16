#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART

#include "DLLNode.h"

#define NULL_TELEM (-111111)
typedef int TElem;
class SetIterator;

class Set {
	//DO NOT CHANGE THIS PART
	friend class SetIterator;

    private:
		DLLNode<TElem>* start;
        DLLNode<TElem>* end;
		int quantity;

    public:
        //implicit constructor
        Set();
		/// \space Theta(1)
		/// \time Theta(1)
		/// \errors throws no custom errors

        //adds an element to the set
		//returns true if the element was added, false otherwise (if the element was already in the set, and it was not added)
        bool add(TElem e);
		/// \time O(size)
		/// \space Theta(1)
		/// \param e Element which will be added iff it is not already part of the set
		/// \return true if e was successfully added to the set, false is it was already present
		/// \errors throws no custom errors
        //removes an element from the set
		//returns true if e was removed, false otherwise
        bool remove(TElem e);
 		/// \time O(size)
		/// \space Theta(1)
		/// \param elem Element which will be removed
		/// \return true if e was present in the set before the method call, false otherwise
		/// \errors throws no custom errors
        //checks whether an element belongs to the set or not
        [[nodiscard]] bool search(TElem elem) const;
		/// \time O(size)
		/// \space Theta(1)
		/// \param elem Element which will be searched for
		/// \return true if elem is part of the set
		/// \errors throws no custom errors

        //returns the number of elements;
        [[nodiscard]] int size() const;
		/// \time Theta(1)
		/// \space Theta(1)
		/// \return size of the set as an int
		/// \errors throws no custom errors

        //check whether the set is empty or not;
        [[nodiscard]] bool isEmpty() const;
		/// \time Theta(1)
		/// \space Theta(1)
		/// \return true if the set has no elements (if size()==0)
		/// \errors throws no custom errors

        //return an iterator for the set
        [[nodiscard]] SetIterator iterator() const;
 		/// \time Theta(1)
		/// \space Theta(1)
		/// \return iterator object for the container
		/// \errors throws no custom errors


        // destructor
        ~Set();
	 	/// \time Theta(size) (all positions have to be freed individually)
		/// \space Theta(1)
		/// \param elem Element which will be removed
		/// \errors throws no custom errors
};





