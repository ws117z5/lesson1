/*This file demonstrate the implementationo of Node ADT*/
#ifndef LEC1_NODE_H
#define LEC1_NODE_H


template <typename T>			
//This Node class can accept any types of data
class Node {
private:
	T data;
	Node<T> * pNext = nullptr;
public:
	Node() {};
	Node(T data) {
		this->data = data;
		this->pNext = nullptr;
	}
	Node<T> & operator [] (int index) {
		Node<T> * n = this;
		for (int i = 0; i < index; i++) {
			n = n->pNext;
		}

		return *n;
	};


	void operator = (T data) {
		this->data = data;
	};

    void setData(T data) {
        this->data = data;
    };

	bool operator == (T data) {
		return this->data == data;
	}

    // & no copy
	T & get() {
		return this->data;
	}

    //return a reference
	Node<T> * getNext() {
		return this->pNext;
	};

	void setNext(T data) {
		this->pNext = new Node(data);
	};


	void setNext(Node<T> * node, Node<T> * next) {
		node->setNext(next);
		this->setNext(node);
	};

	void setNext(T data, Node<T> * next) {
		this->pNext = new Node(data);
		this->pNext->pNext->pNext = next;
	};

	void setNext(Node<T> * node) {
		this->pNext = node;
	};

	void deleteNext() {
		this->pNext = nullptr;
		delete this->pNext;
	};


};

#endif
