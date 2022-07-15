#include<iostream>
#include<climits>
#include<cmath>

using namespace std;


#ifndef HEAP_SWAP
#define HEAP_SWAP
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
#endif
  
// A class for Min Heap
class MinHeap
{
    int * data;
    int capacity; 
    int size;
public:
    MinHeap(int cap) : capacity(cap), size(0) {
        data = new int[cap];
    }
  
    // to heapify a subtree with the root at given index
    void MinHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < this->size && this->data[l] < this->data[i])
            smallest = l;

        if (r < this->size && this->data[r] < this->data[smallest])
            smallest = r;

        if (smallest != i) {
            swap(&this->data[i], &this->data[smallest]);
            MinHeapify(smallest);
        }
    }
  
    int parent(int i) { 
        return (i-1)/2; 
    }
  
    int left(int i) { 
        return (2*i + 1); 
    }
  
    // to get index of right child of node at index i
    int right(int i) { 
        return (2*i + 2); 
    }
  
    // to extract the root which is the minimum element
    int extractMin() {
        if (this->size <= 0)
            return INT_MAX;
            
        if (this->size == 1) {
            this->size--;
            return this->data[0];
        }
    
        // Store the minimum value, and remove it from heap
        int root = this->data[0];
        this->data[0] = this->data[this->size-1];
        this->size--;
        this->MinHeapify(0);
    
        return root;
    }
  
    void decreaseKey(int i, int new_val) {
        this->data[i] = new_val;
        int parent = this->parent(i);
        while (i != 0 && this->data[parent] > this->data[i])
        {
            swap(&this->data[i], &this->data[parent]);
            i = parent;
        }
    }
  
    // Returns the minimum key (key at root) from min heap
    int getMin() { 
        return this->data[0]; 
    }
  
    // Deletes a key stored at index i
    void deleteKey(int i) {
        this->decreaseKey(i, INT_MIN);
        this->extractMin();
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
            cout << "\nOverflow: Could not insert\n";
            return;
        }
    
        this->size++;
        int i = this->size - 1;
        this->data[i] = k;
    
        int parent = this->parent(i);
        // Fix the min heap property if it is violated
        while (i != 0 && this->data[parent] > this->data[i])
        {
            swap(&this->data[i], &this->data[parent]);
            i = parent;
        }
    }
};
