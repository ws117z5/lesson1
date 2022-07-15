#ifndef SAFE_STACK_H
#define SAFE_STACK_H

#include <iostream>
#include <stdexcept> 
#include "SafeNode.h"

template<class T>
class SafeStack {
    private:
    shared_ptr<SafeNode<T>> head = nullptr;
    shared_ptr<SafeNode<T>> tail = nullptr;
    int size = 0;

    public:

    T & operator [] (int index) {
		shared_ptr<SafeNode<T>> n = head;

        if (index > size) {
            //return;
            throw std::out_of_range("Out of range");
        }

		for (int i = 0; i < index; i++) {
			n = n->getNext();
		}

		return n->get();
	};

    SafeStack(T data) {
        SafeNode<T> * _newNode = new SafeNode<T>(data);
		shared_ptr<SafeNode<T>> newNode(_newNode);
        
        head = tail = newNode;
        size++;
    }

    SafeStack() {}

    //add data to the end of the stack
    void push(T data) {
        std::shared_ptr<SafeNode<T>> node_ptr(std::make_shared<SafeNode<T>>(data));
        node_ptr->setPrev(tail);

        if (tail) {
            tail->setNext(node_ptr);
            tail = std::move(node_ptr);
        } else {
            tail = std::move(node_ptr);
            head = tail;
        }

        size++;
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
            tail->getPrev()->lock();
            tail = tail->getPrev();
            tail->deleteNext();
            size--;

            return res;
        }
    }

    void traverse() {
        shared_ptr<SafeNode<T>> tmp = head;

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