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
#import "PriorityQueue.h"

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
// Main class
class MaxHeap {
    int * data;
    int capacity;
    int size;
 
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
 
        if (data[pos] < data[left(pos)]
            || data[pos] < data[right(pos)]) {
 
            if (data[left(pos)] > Heap[right(pos)]) {
                swap(&data[pos], &data[left(pos)]);
                maxHeapify(left(pos));
            } else {
                swap(&data[pos], &data[right(pos)]);
                maxHeapify(right(pos));
            }
        }
    }
 
    void insert(int element) {
        if (this->size == this->capacity)
        {
            //TODO resize 
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }
        
        data[size] = element;
 
        // Traverse up and fix violated property
        int current = size;
        while (data[current] > data[parent(current)]) {
            swap(&data[current], &data[parent(current)]);
            current = parent(current);
        }
        size++;
    }
 
    // Method 8
    // To display heap
    void print()
    {
       
      for(int i=0;i<size/2;i++){
 
            std::cout << "Parent Node : " << data[i];
             
            if(left(i)<size) //if the child is out of the bound of the array
               std::cout << " Left Child Node: " << data[left(i)];
             
            if(right(i)<size) //if the right child index must not be out of the index of the array
                std::cout << " Right Child Node: " <<  data[right(i)] << "\n";
             
        }
           
    }
 
    int extractMax() {
        int popped = data[0];
        data[0] = data[--size];
        maxHeapify(0);
        return popped;
    }
}