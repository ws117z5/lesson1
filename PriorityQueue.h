#pragma once
#include <functional>
#include "Node.h"
#include "Queue.cpp"

template<typename T>
class PriorityQueue : private Queue<T> {
    using Queue<T>::Queue;
    using Queue<T>::head;
    using Queue<T>::size;

    function<bool(T, T)> comparator; 
    bool comparatorIsSet = false;

public:
    PriorityQueue(function<bool(T, T)> cmp) {
        comparator = cmp;
        comparatorIsSet = true;
    }


    void add(T data){
        Node<T> * newParticipant =  new Node<T>{data};

        if (this->head == nullptr) {
            this->head = newParticipant;
            return;
        }

        if (this->comparatorIsSet) {
            this->add(data, this->comparator);
            return;
        }

        Node<T> * tmp = head;

        //another edge case scenario
        while (tmp->get() > data && tmp->getNext() != nullptr) {
            tmp = tmp->getNext();
        }

        if (tmp == head) {
            this->head = newParticipant;
            newParticipant->setNext(tmp);
            tmp->setPrev(newParticipant);
        } else {
            Node<T> * previous = tmp->getPrev();
            previous->setNext(newParticipant);
            newParticipant->setNext(tmp);
            newParticipant->setPrev(previous);
        }

        size++;

    };

    void add(T data, function<bool(T, T)> compare){
        Node<T> * newParticipant =  new Node<T>{data};
        Node<T> * tmp = head;

        while (compare(tmp->get(), data) && tmp->getNext() != nullptr) {
            tmp = tmp->getNext();
        }

        if (tmp == head) {
            this->head = newParticipant;
            newParticipant->setNext(tmp);
            tmp->setPrev(newParticipant);
        } else {
            Node<T> * previous = tmp->getPrev();
            previous->setNext(newParticipant);
            newParticipant->setNext(tmp);
            newParticipant->setPrev(previous);
        }

        size++;

    };

    //TODO get first element and remove it from the queue
    T pop() {
        T a = this->head->get();
        this->head = this->head->getNext();
        return a;
    }

};