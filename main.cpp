#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

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
//lambdas
//concurency
//exceptions

//vectors
//hashtables
//linked list 
//binary trees
//traversal methods
//bfs, dfs, 

//git status - посмотреть статус файлов
//git add <filename> - добавить файлы
//git push - отправить на сервер

struct A {
    int * numberPointer = nullptr;
    A(int number) {
        *numberPointer = number;
    }

    A() {}

    ~A() {
        delete A::numberPointer;
    }
};

int main() 
{
    cout << "Hello world";

    vector<string> vec1{"test", "test2"};
    char arr[] = {"testtest2"}; // \0 
    int arr2[] = {10, 20, 30};

    A classA = A{2};


    int a, *b, **c;
    a = 1;
    b = &a;
    *b = 2;
    c = &b;
    **c = 3;

    cout << "\n" << a;
    cout << *b;
    cout << **c;

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

    cout << arr;

    for (auto x : vec1)
        cout << x << endl;

    for(int n=0; n<length; ++n) {
        std::cout << arr[n] << "\n";
    };


    //possible errors with complex types
    Node<int> node = Node(1);

    node.get() = 2;
};