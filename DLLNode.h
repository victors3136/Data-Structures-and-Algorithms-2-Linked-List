//
// Created by victor on 18/04/2023.
//

#ifndef L02_DLLNODE_H
#define L02_DLLNODE_H

template <typename TElem>
class DLLNode
{
private:
	TElem data;
	DLLNode* before;
	DLLNode* next;
public:
	DLLNode(): before(nullptr), next(nullptr){};

	[[maybe_unused]] explicit DLLNode(TElem value): before(nullptr), next(nullptr), data(value){};

	[[maybe_unused]] DLLNode(TElem value, DLLNode* predecessor, DLLNode* successor):before(predecessor), next(successor), data(value){};
    ~DLLNode()= default;

    TElem getData() const {
        return data;
    }

	[[maybe_unused]] void setData(TElem newData) {
        DLLNode::data = newData;
    }

	[[maybe_unused]] DLLNode *getBefore() const {
        return before;
    }

	[[maybe_unused]] void setBefore(DLLNode *newPredecessor) {
        DLLNode::before = newPredecessor;
    }

    DLLNode *getNext() const {
        return next;
    }


	[[maybe_unused]] void setNext(DLLNode *newSuccessor) {
        DLLNode::next = newSuccessor;
    }


    bool operator==(const DLLNode &other) const {
        return data == other.getData();
    }

    bool operator!=(const DLLNode &other) const {
        return data != other.getData();
    }
};

#endif //L02_DLLNODE_H
