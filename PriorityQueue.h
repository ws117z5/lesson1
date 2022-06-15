#pragma once
#include "Node.h"
#include "Queue.h"

template<typename T>
class PriorityQueue : private Queue<T> {
    using Queue<T>::Queue;

    void add(T data){
        Node<T> * newParticipant =  new Node<T>{data};
        Node<T> * tmp = head;

        while (tmp->get() < data && tmp->getNext() != nullptr) {
            tmp = tmp->getNext();
        }

        // data > tmp->data
        // tmp->next == nullptr;

        // 5
        // 2 3 4 >5<  8 9

        if(tmp->getNext() != nullptr) {
            Node<T> * _tmp = tmp->getNext(); //8
            tmp->setNext(newParticipant);   //4->5 
            newParticipant->setNext(_tmp);  //5->8
        } else {
            // 5
            // 2 3 4 >5<
            tmp->setNext(newParticipant);   //4->5
        }
        size++;

    };
}