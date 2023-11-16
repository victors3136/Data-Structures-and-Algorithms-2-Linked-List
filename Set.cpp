#include "Set.h"
#include "SetIterator.h"

Set::Set(): start(nullptr), end(nullptr), quantity(0){}


bool Set::add(TElem elem) {
    if(start == nullptr){
        start = new DLLNode<TElem>;
        start->setNext(nullptr);
        start->setBefore(nullptr);
        start->setData(elem);
        end = start;
		quantity = 1;
        return true;
    }
    auto current = start;
    while(current != nullptr && current->getData() != elem){
        current= current->getNext();
    }
    if(current!= nullptr){
        return false;}
    auto newNode = new DLLNode<TElem>;
    newNode->setData(elem);
    newNode->setBefore(end);
    newNode->setNext(nullptr);
    if(start == nullptr){
        start = newNode;
    }
    else{
        end->setNext(newNode);
    }
    end = newNode;
	quantity++;
    return true;
}


bool Set::remove(TElem elem) {
    auto current = start;
    while(current != nullptr && current->getData() != elem){
        current= current->getNext();
    }
    if(current== nullptr) {
        return false;
    }
    if(start == end){
        start = nullptr;
        end = nullptr;
    }else if(current == start){
        start = start->getNext();
        start->setBefore(nullptr);
    }else if(current == end){
        end = end->getBefore();
        end->setNext(nullptr);
    }else{
        (current->getNext())->setBefore(current->getBefore());
        ((current->getBefore())->setNext(current->getNext()));
    }
    delete current;
	quantity --;
    return true;
}

bool Set::search(TElem elem) const {
    auto current = start;
    while(current != nullptr && current->getData() != elem){
        current= current->getNext();
    }
    if(current== nullptr) {
        return false;
    }
	return true;
}


int Set::size() const {
	return quantity;
}


bool Set::isEmpty() const {
	return(quantity == 0);
}


Set::~Set() {
    DLLNode<TElem>* current = start;
    while (current != nullptr) {
        DLLNode<TElem>* next = current->getNext();
        delete current;
        current = next;
    }
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


