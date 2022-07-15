/**
 * @file MaxHeap.h
 * @author Vladimir Koroteev (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-21
 * 
 *  Rewritten Of The GeeksForGeeks Java Version
 */
#pragma once
#import <iostream>

#ifndef HEAP_SWAP
#define HEAP_SWAP
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
#endif
 
// Main class
class MaxHeap {
    int * data;
    int capacity;
    int size;
 
public:
    MaxHeap(int cap) {
        // This keyword refers to current instance itself
        this->capacity = cap;
        this->size = 0;
        data = new int[cap];
    }
 
    int parent(int pos) { 
        return (pos - 1) / 2; 
    }
 
    int left(int pos) { 
        return (2 * pos) + 1; 
    }
 
    int right(int pos){ 
        return (2 * pos) + 2; 
    }

    //[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    /**
     *          0
     *      1       2
     *  3     4   5     6
     */
 
    bool isLeaf(int pos)
    {
        if (pos > (size / 2) && pos <= size) {
            return true;
        }
        return false;
    }
 
    void maxHeapify(int pos)
    {
        if (isLeaf(pos))
            return;
 
        if (data[pos] < data[left(pos)] || data[pos] < data[right(pos)]) {
 
            if (data[left(pos)] > data[right(pos)]) {
                swap(&data[pos], &data[left(pos)]);
                maxHeapify(left(pos));
            } else {
                swap(&data[pos], &data[right(pos)]);
                maxHeapify(right(pos));
            }
        }
    }

    void print() {
        for (int i=0; i < this->size; i++) {
            cout << this->data[i] << " ";
        }
        cout << "\n";
    }
 
    void insert(int k) {
        if (this->size == this->capacity)
        {
            //TODO resize 
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }
        
       this->data[size] = k;
 
        // Traverse up and fix violated property
        int currentIdx = size;
        int parentIdx = this->parent(currentIdx);
        while (this->data[currentIdx] > this->data[parentIdx]) {
            swap(&this->data[currentIdx], &this->data[parentIdx]);
            currentIdx = parent(currentIdx);
        }
        size++;
    }
 
    int extractMax() {
        int popped = data[0];
        data[0] = data[--size];
        maxHeapify(0);
        return popped;
    }
};