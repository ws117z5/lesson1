/*This file demonstrate the implementationo of Node ADT*/
#ifndef LEC1_NODE_H
#define LEC1_NODE_H

		
//This Node class can accept any types of data
template<class T>
class Node {
private:
	T data;
	Node * pNext = nullptr;
	Node * pPrev = nullptr;
public:
	Node() {};
	Node(T data) {
		this->data = data;
		this->pNext = nullptr;
		this->pPrev = nullptr;
	}

	~Node() {
		this->pPrev->pNext = this->pNext;
		this->pNext->pPrev = this->pPrev;

		delete this;
	}

	void add(T data) {
		//this  * Node node1
		Node<T> * newNode = new Node<T>{data};
		
		newNode->pNext = this->pNext; 	// 2 -> 3
		this->pNext	= newNode; 			// 1 -> 2 
		newNode->pNext->pPrev = newNode;// 2 <- 3
		newNode->pPrev = this;			// 1 <- 2

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

	bool equal(Node n)  {
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
	Node * getNext() {
		return this->pNext;
	};

	//return a reference
	Node * getPrev() {
		return this->pPrev;
	}

	void setNext(T data) {
		this->pNext = new Node(data);
		this->pNext->pPrev = this;
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
