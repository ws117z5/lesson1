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
    char * a = "helloworld";
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

    int f5 = fib(7);

    return 0;
};