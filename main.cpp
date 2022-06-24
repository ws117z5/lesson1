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

int fib(int n, HashTable<int, int> * storage) {
    if (n <= 2) {
        return 1;
    }

    if(storage->isSet(n)) {
        //we trace if we accessed the element
        cout << n << " from cache " << storage->get(n) << "\n";
        return storage->get(n);
    }

    storage->insert(n, int(fib(n-2, storage) + fib(n-1, storage)));
    return storage->get(n);
};



class MyString {
public:
    string str;

    MyString() : str("") {}
    MyString(string s) : str(s) {}

    bool operator > (MyString other) {
        int sizeCurrent = str.length();
        int sizeOther = other.str.length();

        //TODO try this
        //TODO Vladimir polimorphic comparator example
        int smallest = (sizeCurrent < sizeOther) ? sizeCurrent : sizeOther;

        for (int i=0; i < smallest; i++) {
            if (str[i] < other.str[i]) {
                return false;
            }
        }
        return sizeCurrent < sizeOther;

    }
};

int main() 
{
    MyString s1 = MyString{"a word"};
    MyString s2 = MyString{"a word 2"};
    MyString s3 = MyString{"a word 1"};
    

    function<bool(string, string)> compare = [&](string str1, string str2) {
        int sizeCurrent = str1.length();
        int sizeOther = str2.length();

        int smallest = (sizeCurrent < sizeOther) ? sizeCurrent : sizeOther;

        for (int i=0; i < smallest; i++) {
            if (str1[i] < str2[i]) {
                return false;
            }
        }
        return sizeCurrent < sizeOther;
    };
    
    PriorityQueue<string> pq = PriorityQueue<string>("test");
    pq.add("a word", compare);
    pq.add("a word 2", compare);
    pq.add("a word 1", compare);

    

    //ASCII 
    //ISO1250
    //char * a = "helloworld";
    //UTF8 UTF16

    MyString firstPQElement = pq.pop();

    string test2[2] = {"test1", "test2"};

    // hashTable 
    // key value
    // key 
    // get (key) -> value
    // 23 17

    // size 23 -> 24 
    // 
    // capacity
    // 
    // hash(10101) -> int 
    // int % prime 
    // 0 -> prime-1
    // gcd(1, prime-1) = 1
    // 1/2^32
    // 

    // key
    // hash<T> (key) -> int fast
    //  hash<T> (key) % prime -> [0]->[prime-1]
    // 229487498539485 % 29 
    //  23
    // resize()
    // arr[23]
    // arr[0]
    // arr[1]->arr[1]->
    // arr[2]
    // if collision occurs we increment the prime 
    // 1. getNextPrime(prime+1) 
    // 2. store tmp values of current inserted data
    // 3. clear out exists, data arrays
    // 4. recalculate new keys and insert all the old data valuse/keys
    // 5. add new value
    HashTable<string, string> ht = HashTable<string, string>();
    for (auto val : test2) {
        ht.insert(val, val);
    }

    ht.insert("one", "first message");
    //ht.get("one");

    ht["two"] = "assigned for a key";
    ht["one"] = "first message(edited)";
    string test = ht["one"];
    string test3 = ht["two"];

    string test1 = ht.get("test1");

    HashTable<int, int> storage = HashTable<int, int>{};
    int f5 = fib(7, &storage);

    //TODO Look at BinarySearchTree.h file, prepare questions.
    AVLTree<int> AVLRoot = AVLTree<int>();
    AVLRoot.add(10);
    AVLRoot.add(20);
    AVLRoot.add(30);
    AVLRoot.add(40);
    AVLRoot.add(50);
    AVLRoot.add(25);

    AVLRoot.visualize();    
    //fixed it, can you guess how?
    AVLRoot.breadthFirstTraversal([](int n) {
        cout << n << " ";
    });


    //TODO Homework
    char * str = (char*) "hello world";

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

    //6. can we create an avl tree without pointers? read about heap data structure

    return 0;
};