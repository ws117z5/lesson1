#include <iostream>

using namespace std;

template<class Temp>
class Queue {
private:
    Queue<Temp> * tail = nullptr
    Queue<Temp> * head = nullptr
    int size = 0
public:

    void add(Temp data){
        Queue<Temp> * NewParticipant =  new Queue<Temp>{data};
        this->tail = NewParticipant
        NewParticipant->tail = nullptr
        size++

    };

    void pop() {
        if (size == 0) {
            cout<<"Queue is empty!"
        } 
        if (size == 1) {
            delete this
            head = tail = nullptr
            size--
        } else {
           this->tail = head
        
           delete this
           size-- 
        }
    };
};
       