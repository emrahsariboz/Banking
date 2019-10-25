#include "Minheap.h"

Minheap::Minheap(int cap)
{
    heap_size = 0;
    capacity = cap;
    arr = new int[capacity];
}


int Minheap::left(int i){
    return  2*i  + 1;
}

int Minheap::right(int i){
    return 2*i + 2;
}

int Minheap::parent(int i){
    return i/2;
}

void Minheap:: swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Minheap::getMin(){
    return arr[0];
}

void Minheap::insertKey(int k){
    if(heap_size == capacity){
        cout << "Capacity is full!"<<endl;
    }

    heap_size++;
    int i = heap_size - 1;
    arr[i] = k;

    while(i != 0 && arr[parent(i) > arr[i]]){
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

