#pragma once
#include <iostream>
#include "Node.h"
#include <stdexcept>

using namespace std;

//Queue LIFO

template<class Temp>
class Queue {
protected:

    Node<Temp> * tail = nullptr;
    Node<Temp> * head = nullptr;

    int size = 0;
public:
    Queue() {}
    
    Queue(Temp data) {
        //Queue 
        this->tail = this->head = new Node<Temp>{data};
        size++;
    }

    void add(Temp data){
        Node<Temp> * newParticipant =  new Node<Temp>{data};

        if (this->size == 0) {
            this->tail = this->head = newParticipant;
        } else {
            this->tail->setNext(newParticipant);    // add to chain
            this->tail = newParticipant;            //set tail link to newParticipant
        }

        size++;
    };
    //stack 
    // 1 -> 2 -> 3
    //queue
    // 1 -> 2 -> 3
    // 1, 2, 3, 4 / 5 6 7 8
    Temp pop() {
        if (size == 0) {
            //cout << "Queue is empty!";
            throw std::out_of_range("length is zero");
        } 
        if (size == 1) {
            Temp tmp = head->get();
            delete head;
            size--;
            return  tmp;
        } else {
            Temp tmp = head->get();
            head = head->getNext();
            size--;
            return tmp;
        }
    };

    void traverse() {
        Node<Temp> * tmp = head;

        while(tmp->hasNext()) {
            std::cout << tmp->get() << ", ";
            tmp = tmp->getNext();
        }

        std::cout << tmp->get() << "\n";
    }

    bool empty() {
        return this->size == 0;
    }
};
       