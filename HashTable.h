/**
 * @file HashTable.h
 * @author Vladimir Koroteev (vladimir@koroteev.dev)
 * @brief 
 * @version 0.1
 * @date 2022-06-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>
#include <cmath>
#include <functional>
#include <exception>
#include <type_traits>
#include <array>

typedef unsigned long long uint64; 

using namespace std;


uint64 isPrime(uint64 n) {
    int prime_flag = 0;
    if(n > 1) {
        //29
        for (int i = 2; i <= (int) sqrt(n); i++) {
            if (n % i == 0) {
                prime_flag = 1;
                break;
            }
        }
        if (prime_flag == 0) {
            return true;
        } else {
            return false;
        }
    }
        
    return false;
};

uint64 getPrimeLargerThan(uint64 n) {
    for (int i = n; i < n*2; i++) {
        if(isPrime(i)) {
            return i;
        }
    }
    return 0;
};
//
// a        1 1 0 0 
// b        0 1 1 0
// a XOR b  1 0 1 0

//binary number 0b01
//hex number    0xff
uint64 murmur64(uint64 h) {
    //      0...........64
    // xor  32...64
    // mul some number
    // xor  32...64
    // mul some different numebr
  h ^= h >> 33;
  h *= 0xff51afd7ed558ccdL;
  h ^= h >> 33;
  h *= 0xc4ceb9fe1a85ec53L;
  h ^= h >> 33;
  return h;
}



template<typename K, typename V, int N = 0>
class HashTable {
private:
    V * data;
    K * keys;
    bool * exists;
    uint64 size = 0;
    uint64 cap = 0;
public:
    HashTable() {
        //prime numbers are the key since it's factors are 1 and p => n%p will provide a unique solution in 1-p range
        this->cap = getPrimeLargerThan(20);
        this->data = new V[cap];
        this->keys = new K[cap];
        this->exists = new bool[cap];
        for (int i = 0; i< cap;i++) {
            this->data[i] = V{};
            if (N > 0 && std::is_array<K>::value) {
                //this->keys[i]

            } else {
                this->keys[i] = K{};
            }
            this->exists[i] = false;
        }
    }

    ~HashTable() {
        //delete[] data;
        //delete[] exists;
    }

    V & operator [] (K key) {
		uint64 hash = getHash(key);
        uint64 index = hash % this->cap;

        if(!this->exists[index]) {
            this->keys[index] = key;
            this->exists[index] = true;
        }
        
        return this->data[index];
	}

    uint64 getHash(const K &key) {
        //serialize data bits into long long 
        //here we take bits stored inside data address 
        //and store them in a long long variable. 
        //technically this should be a hash function 
        //but we will do that later
        uint64 bits_64 = *(uint64 *) &key;
        uint64 hash = murmur64(bits_64);

        //or we can use std lib
        //std::hash<K> hash_key;
        //uint64 hash = hash_key(key);

        return hash;
    }

    void insert(const K (&keys) [N], const V &value) {
        uint64 key = 0;
        int size = sizeof(keys)/sizeof(keys[0]);
        for (int i = 0; i < size; i++) {
            key += keys[i];
            if (i < size-1) key <<= sizeof(keys[0]); 
        }

        if(this->cap <= this->size) {
            //we need to resize the array
        }
        uint64 hash = getHash(key);
        uint64 index = hash % this->cap;

        //if collision occured
        //TODO get rid of exists array
        if(this->exists[index]) {
            //resize data array
        }

        this->data[index] = value;
        this->keys[index] = key;
        this->exists[index] = true; 

        this->size++;
    }

    void insert(const K &key, const V &value) {
        if(this->cap <= this->size) {
            //we need to resize the array
        }
        uint64 hash = getHash(key);
        uint64 index = hash % this->cap;

        //if collision occured
        //TODO get rid of exists array
        if(this->exists[index]) {
            //resize data array
        }

        this->data[index] = value;
        this->keys[index] = key;
        this->exists[index] = true; 

        this->size++;
    }

    V get(const K (&keys) [N]) {
        uint64 key = 0;
        int size = sizeof(keys)/sizeof(keys[0]);
        for (int i = 0; i < size; i++) {
            key += keys[i];
            if (i < size-1) key <<= sizeof(keys[0]); 
        }
        uint64 hash = getHash(key);
        uint64 index = hash % this->cap;

        if(!this->exists[index]) {
            return V{};
        }

        return this->data[index];
    }

    V get(const K &key) {
        uint64 hash = getHash(key);
        uint64 index = hash % this->cap;

        if(!this->exists[index]) {
            return V{};
        }

        return this->data[index];
    }

    bool isSet(const K (&keys) [N]) {
        uint64 key = 0;
        int size = sizeof(keys)/sizeof(keys[0]);
        for (int i = 0; i < size; i++) {
            key += keys[i];
            if (i < size-1) key <<= sizeof(keys[0]); 
        }

        uint64 hash = getHash(key);
        uint64 index = hash % this->cap;

        return this->exists[index];
    }

    bool isSet(const K &key) {
        uint64 hash = getHash(key);
        uint64 index = hash % this->cap;

        return this->exists[index];
    }

    void remove(const K &key) {

    }
};