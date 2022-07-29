#include <iostream>


#include <string>
#include "lesson2.cpp"
#include "lesson3.cpp"
//#include "HashTable.h"
#include "Sort.h"
#include "Memory.cpp"
#include "Graph.h"

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
//exceptions
//stack
//queue
//btrees            
//steams
//concurency        thread, mutex


//vectors
//hashtables
//linked list 
//binary trees      #we are around here
//traversal methods
//bfs, dfs, 

//git status - посмотреть статус файлов
//git add <filename> - добавить файлы
//git push - отправить на сервер
//git pull - ...

namespace One {
    const int i = 1;
    namespace Two {
        namespace Three {
            const int i = 0;
        }
    }
}

using namespace One;

class Allocation {
private:
    std::string first;
    std::string second;
    int i;
public:
    Allocation() = default;

    Allocation(char *  f, char * s, int i) : first(f), second(s), i(i) {
        //
    }

    Allocation(const std::string & f, const std::string & s, int i) : first(f), second(f), i(i) {
        //f += " ";
        //
    }

    Allocation(std::string && f, std::string && s, int i) : first(std::move(f)), second(std::move(s)), i(i) {
        //
    }

};

int main() 
{
    //thread 

    // [0] 1 2 3 (4) 5 6
    // [1] 1 2 3 4 5 6
    // [2] 4 5 6 7

    //tread(method, params)
    // callback
    // future 
    // async/await
    // promise
    // atomic


    // t = await myfunc()

    //cout << Two::Three::i << endl;
    //cout << One::i << endl;

    //thread(method, param)

    //thread -> method -> callback(results)
    //do someth
    //l3::not_main(l3::NotSafe, 3);   //will crash

    //l3::not_main(l3::Safe, 3);      //will hold, but data integrity is not guaranteed
    //l3::not_main(l3::Safest, 3);    //will hold and data wont be lost
    //l2::not_main();               //heaps

    //bash sample
    //for i in {1..100}; do ./a.out; done | sort | uniq -c

    //MemoryTest::main();


    //TODO Homework
    //1. write a for loop that will print this string inline letter by letter

    //2. write a foreach (type val : arr) loop that would print str letter by letter 
    //(hint: you would have to convert string to another type)

    //3. write a while loop that would print ascii number or each character 
    //(hint: str is a pointer, so we can access it's memory by incrementing the reference address)

    //4. Modify the Node class, we want to have a simple Node class that can only move forward (pNext)
    // and another class that extends Node(#nameityourself) that would use Node functions, and add pPrev member
    // , add/modify pPrev related functions into it. After it works, change Classes that uses current Node, to 
    // #nameityourself, check if everything still works


    //5. mix'n'match imagine that we have a hashtable but we dont resize the array every time we hit a collision, 
    // instead of actual values we store Nodes with values, and when the collision occurs, we put the current input into pNext
    // This node should store both key and value, so you have two options here(pick one):
    // (a) Create a class that would store key and value, and use it as a data member of a basic Node 
    // (b) Create an extended class for Node, that would have a key parameter.
    // Wrap your work into A LinkedHashTable.h file/class

    /**
     * hash % capacity
     * sqrt(cap)
     * 1    [key, value] -> [key, value] -> ... -> sqrt(cap) 
     * 2    [key, value]
     * 3
     * 4
     * 5
     * 6
     * 7
     * 
     */

    //6. can we create an avl tree without pointers? read about heap data structure

    gr::graph_test();

    int n [] = {1, 4, 15, 7, 10};
    // 0 1 0 0 1 0 0 1 0 0 1 0 0 0 0 1
    // 0 1 1 1 2 2 2 3 3 3  4  4  4  4  4  5
    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    // 1 4 7 10 15
    int size = sizeof(n)/sizeof(n[0]);
    //selectionSort(n, size);
    //bubbleSort(n, size);

    std::vector<int> nv{1, 4, 15, 7, 10};
    //std::vector<int> sorted = countSort(nv);

    // for (int i = 0; i < size; i++) {
    //     cout << sorted[i] << " ";
    // }


    //mh.print();
 
    std::vector<int> sorted = heapSort(nv);

    for (auto val : sorted) {
        cout << val << " ";
    }
    cout << "\n";



    std::string f = "John";

    std::string l = "Smith";
    Allocation * a = new Allocation("John", "Smith", 0);
    Allocation * b = new Allocation(f, l, 1);
    return 0;
}



