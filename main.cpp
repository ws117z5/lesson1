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



int main() 
{
    cout << "Hello world";

    vector<string> vec1{"test", "test2"};
    char arr[] = {"testtest2"}; // \0 
    int arr2[] = {10, 20, 30};

    int a, *b, **c;
    a = 1;
    b = &a;
    *b = 2;
    c = &b;
    **c = 3;

    int length = sizeof(arr)/sizeof(arr[0]);

    /**
     * 01 1
     * 02 2
     * 03 3
     * 04
     * 
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