#include <iostream>
#include <string>
#include <vector>
//#include "Node.h"
#include "AStar.h"
#include <thread>
#include "Node.h"
#include "Stack.h"
#include <ctime>
#include <fstream>

using namespace std;


//types of languages
//c++ language
//git
//basic types
//pointers
//classes
//constructors
//destructors
//mutable immutable
//static variables
//templates         
//lambdas           #we are around here
//concurency        thread, mutex
//exceptions
//stack
//queue
//steams



//vectors
//hashtables
//linked list 
//binary trees
//traversal methods
//bfs, dfs, 

//git status - посмотреть статус файлов
//git add <filename> - добавить файлы
//git push - отправить на сервер
//git pull - ...

struct A {
public:
    static int someStaticVar;
    const int i = 1;
    int *numberPointer = new int;
    A(int number) {
        *numberPointer = number;
    }

    virtual void someFunction() {
        cout << "Class A here" << endl;
    }

    A() {
        //someth
    }

    ~A() {
        delete A::numberPointer;
    }
private:
    void somePrivateFunc() {
        cout << "This is private" << endl;
    }
};

class C {
public:
    void someOtherFunction() {
        cout << "Class C here" << endl;
    }
};

class B : public A, C {
public:
    B(int i) : A(i) {

    }
    void someFunction() {
        cout << "B lass here" << endl;
    }

    void dosomething(int i, int j, function<void(int)> callback) {
        int newData = i+j;
        cout << "here something was done" << endl;
        callback(newData);
    }
};

class animal {
    int weight;
    int length;
    string habitat;

    virtual void talk() {

    }
};

class cat : animal  {
    void talk() {
        cout << "Meow" << endl;
    }
};

class dog : animal {
    void talk() {
        cout << "Wof" << endl;
    }
};

int A::someStaticVar = 1;

//template of a stack
template<class T>
class storage {
public:
    T arr[20];
    int position = -1;
    T pull() {
        if (position > -1) {
            return arr[position--];
        }

        return 0;
    }

    void push(T i) {
        arr[++position] = i;
    }
};

struct LinkedList {
    int i;
    LinkedList * next = nullptr;

    void push(int i) {
        LinkedList nl = LinkedList{i};

        //LinkedList * tmp = &this;
        //while (tmp.next != nullptr) {
             //tmp = tmp.next;
        //}
        //tmp.next = &nl;
    }

    int pop() {
        //
    }
};

void someFunc() {
    //do someth
};

int main() 
{
    /**
     * @brief 
     * stack
     * 1    someFunc()
     * 2        *
     * 3        *
     * 4    arr[]
     * 5    arr[0]
     * 6    arr[1]
     * 7    arr[2]
     * 8    Node1
     * 9    data
     * 10   ptr = 17
     * 11
     * 12
     * ...
     * 17   Node2
     * 18   data
     * 19   ptr 
     */

    // node1 (data, ptr) -> node2 (data, ptr) 
    cout << &someFunc << "\n";
    function<void(int)> callback = [&](int i) {
        cout << "We have got some calculated data: " << i << " then we've added 1";
        return i+1;
    };

    vector<string> vec1{"test", "test2"};
    char arr[] = {"testtest2"}; // \0 
    int64_t arr2[] = {10, 20, 30};

    cout << *(arr2+4) << "\n";

    Node<int> * firstNode = new Node<int>{1};
    Node<int> firstNode_data = *(firstNode);
    Node<int> * firstNode_ptr = &firstNode_data;

    cout << firstNode << "\n";


    //int*arrPtr;
    //arrPtr = arr2;

    //cout << *(arrPtr+2) << endl;

    int x = 1;
    //lvalue/rvalue
    A classA = A{2};
    A * cls = &classA;
    A *classARef = new A(1);

    B classB = B{1};
    classB.someStaticVar++;

    //classB.dosomething(1, 2, callback);

    //classB.someFunction();

    //cout << classA.someStaticVar << endl;

    storage<string> mystore = storage<string>{};
    mystore.push("hi");
    //cout << mystore.pull() << endl;


    int a, *b, **c;
    a = 1;
    b = &a;
    *b = 2;
    c = &b;
    **c = 3;

    //cout << "\n" << a;
    //cout << *b;
    //cout << **c;

    int length = sizeof(arr)/sizeof(arr[0]);
    /**
     * 01 a1
     * 02 a2
     * 03 a3
     * 04 ...
     * 
     * 
     * 
     * 11 b1
     */

    //cout << arr;

    for (auto x : vec1)
        //cout << x << endl;

    for(int n=0; n<length; ++n) {
        //std::cout << arr[n] << "\n";
    };

    //possible errors with complex types
    // Node<int> node = Node(1);


    // node.get() = 2;

    // node.setNext(4);
    // node.setNext(6);

    // node.traverse();

    //Homework
    //Make Node class as a template
    //create class NodeStorage that will store, add, remove, and traverse Node elements
    //Make NodeStorage and Node both templated classes
    //Node storage should be in it's own NodeStorage.h file

	return 0;
};