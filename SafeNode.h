
#ifndef SAFE_NODE_H
#define SAFE_NODE_H

#include <iostream>

using namespace std;

//This Node class can accept any types of data
template<class T>
class SafeNode 
{
private:
	T data;
	shared_ptr<SafeNode<T>> pNext = nullptr;
	weak_ptr<SafeNode<T>> pPrev;
public:
	SafeNode() {}

	SafeNode(T const& data) : data(data) {
		this->pNext = nullptr;
	}

	void operator = (T data) {
		this->data = data;
	};

    void setData(T data) {
        this->data = data;
    };

	bool operator == (T data) {
		return this->data == data;
	}

	bool equal(SafeNode<T> n)  {
		return n->data == this->data;
	}

	// & no copy
	T & getRef() {
		return this->data;
	}

	T get() {
		return this->data;
	}

    //return a reference
	shared_ptr<SafeNode<T>> getNext() {
		return this->pNext;
	};

	//return a reference
	shared_ptr<SafeNode<T>> getPrev() {
		return this->pPrev;
	}

	void setNext(shared_ptr<SafeNode<T>> sharedNode) {
		this->pNext = sharedNode;
	}

	void setPrev(shared_ptr<SafeNode<T>> sharedNode) {
		this->pPrev = sharedNode;
	}

	void deleteNext() {
		this->pNext = nullptr;
	}

	bool hasNext() {
		return this->pNext != nullptr;
	}

	bool hasPrevious() {
		return this->pPrev != nullptr;
	}
};

#endif
