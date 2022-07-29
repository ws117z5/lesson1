#ifndef SORT_H
#define SORT_H

#include <algorithm>
#include <iostream>
#include <vector>
#include "MinHeap.h"

template<typename T>
void selectionSort(T arr[], int size)
{
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < size-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        int min_idx = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                 min_idx = j;
            }       
        }
        
        // Swap the found minimum element
        // with the first element
        std::swap(arr[min_idx], arr[i]);
    }
}
//O(n^2)


template<typename T>
void bubbleSort(T arr[], int size)
{
    //1, 4, 15, 7, 10
    int i, j;
    bool swapped;
    for (i = 0; i < size-1; i++)
    {
        swapped = false;
        for (j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        // IF no two elements were swapped 
        // by inner loop, then break
        if (swapped == false)
        break;
    }
}
//5 2 6 4 9
//5<->2
//2 5 6 4 9
//5 6 ok
//6 <-> 4
//2 5 4 6 9
//2 5 ok
//5 <-> 4 
//ok, ok, ok
//2 4 5 6 9
//O(n^2)

std::vector<int> countSort(std::vector<int>& arr)
{
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    int size = arr.size();
 
    std::vector<int> count(range), output(size);
    for (int i = 0; i < size; i++)
        count[arr[i] - min]++;
 
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
 
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
 
    return output;
}
//time complexity O(n)
//space complexity O(n+range)


std::vector<int> heapSort(std::vector<int> & arr) {
    MinHeap _tmp = MinHeap(arr);

    return _tmp.dfs();

}

#endif