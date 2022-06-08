#ifndef NODE_NEW_H
#define NODE_NEW_H

#include <iostream>
#include <stdexcept> 
#include "Node.h"


//Stack st = Stack{1}
//1 -> 2 -> 3 -> 4 
//1
//1 -> 2 -> 3 push -> 4 pop 
//LinkedList
//only head pointer
//use only pNext
//Queue
//push add to tail
//pop takes first
// push
// pop 
template<class T>
class Stack {
    private:
    Node<T> * head = nullptr;
    Node<T> * tail = nullptr;
    int size = 0;

    public:

    T & operator [] (int index) {
		Node<T> * n = head;

        if (index > size) {
            //return;
            throw std::out_of_range("Out of range");
        }

		for (int i = 0; i < index; i++) {
			n = n->getNext();
		}

		return n->get();
	};

    Stack(T data) {
        head = tail = new Node<T>(data);
        size++;
    }

    Stack() {}

    // T pop_tmp() {
    //     //1 -> 2-> 3
    //     Node * tmp = head;
    //     if(tmp == nullptr) {
    //         //
    //     }

    //     if(tmp->pNext == nullptr) {
    //         //
    //     }

    //     while(tmp->pNext->pNext != nullptr) {
    //         tmp = tmp->pNext;
    //     }

    //     T ret = tmp->pNext->get();
    //     tmp->pNext = nullptr;
    //     return ret;
    // }

    // Stack(T * data) {
    //     int size = *(&data + 1) - data;
    //     if (size == 0) {
    //         return;
    //     }
    //     head = tail = new Node<T>(data[0]);
    //     size++;
       
    //     for (auto i = 1; i < size; i++) {
    //         tail->setNext(data[i]);
    //         tail = tail->getNext();
    //         size++;
    //     } 
    //     size++;
    // }

    //add data to the end of the stack
    void push(T data) {

        if(head == nullptr) {
            head = tail = new Node<T>(data);
        } else {
            tail->setNext(data);
            tail = tail->getNext();
            size++;
        }
    }

    T pop() {

        if (size == 0) {
            throw std::out_of_range("length is zero");
        } else if (size == 1) {
            T res = head->get();
            tail = head = nullptr;
            size = 0;
            

            return res;
        } else {
            T res = tail->get();
            tail = tail->getPrev();
            tail->deleteNext();
            size--;

            return res;
        }
    }

    void traverse() {
        Node<T> * tmp = head;

        while(tmp->hasNext()) {
            std::cout << tmp->get() << ", ";
            tmp = tmp->getNext();
        }

        std::cout << tmp->get() << "\n";
    }

    int length() {
        return size;
    }


};

#endif