#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "AVLTree.h"
#include <thread>
#include "Stack.h"
#include <ctime>
#include <fstream>
#include <functional>
#include "Queue.cpp"
#include "PriorityQueue.h"
#include "HashTable.h"

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

int fib(int n) {
    if (n <= 2) {
        return 1;
    }

    return fib(n-2) + fib(n-1);
};

int main() 
{
    PriorityQueue<string> pq = PriorityQueue<string>("test");
    pq.add("a word");
    pq.add("a word 2");

    string test2[2] = {"test1", "test2"};
    HashTable<string, string> ht = HashTable<string, string>();
    for (auto val : test2) {
        ht.insert(val, val);
    }

    string test1 = ht.get("test1");

    int f5 = fib(7);

    return 0;
};