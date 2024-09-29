/*
Name: Alyssa Duranovic
ASUID: 1224512913
*/

#include "data_structures.h"
#include <cstdlib>
#include <cstdio>


void swap(ELEMENT** el1, ELEMENT** el2){
    ELEMENT* temp = *el1;
    *el1 = *el2;
    *el2 = temp;
}

void heapify(HEAP *Heap, int k){
    //Heap->heapifyCalls++;
    int smallest = k;
    int left = (2*k)+1;
    int right = (2*k)+2;

    if((left < Heap->size) && (Heap->A[left]->key < Heap->A[smallest]->key)){
        smallest = left;
    }
    if((right < Heap->size) && (Heap->A[right]->key < Heap->A[smallest]->key)){
        smallest=right;
    }
    if(smallest != k){
        swap(&Heap->A[k], &Heap->A[smallest]);
        heapify(Heap, smallest);
    }
}

void BuildHeap(HEAP *Heap){
    int n = Heap->size;
    for(int k = (n/2)-1; k>=0; k--){
        heapify(Heap, k);
    }
}

void decreaseKey(int position, double newKey, HEAP *Heap){
    if(Heap->size == 0){
        //fprintf(stderr, "Error: heap is empty\n");
        return;
    }else if((position<0) || (position>=Heap->size)){
        fprintf(stderr, "Error: invalid call to DecreaseKey\n");
        return;
    }else if(newKey >= Heap->A[position]->key){
        fprintf(stderr, "Error: invalid call to DecreaseKey\n");
        return;
    }
    
    Heap->A[position]->key = newKey;
    while(position > 0 && Heap->A[(position-1)/2]->key > Heap->A[position]->key){
        int parentPosition =  (position-1)/2;
        swap(&Heap->A[parentPosition], &Heap->A[position]);
        position = parentPosition;
    }
}

void insert(double newKey, HEAP *Heap){
    if(Heap->size>=Heap->capacity){
        fprintf(stderr, "Error: heap is full\n");
        return;
    }
    ELEMENT* element = (ELEMENT *)malloc(sizeof(ELEMENT));
    if(!element){
        fprintf(stderr, "Error: memory allocation failed for element\n");
        return;
    }
    element->key = 10000000000;
    Heap->A[Heap->size] = element;
    Heap->size++;
    decreaseKey(Heap->size-1, newKey, Heap);
}

void extractMin(HEAP *Heap){
    if(Heap->size == 0){
        //fprintf(stderr, "Error: heap is empty\n");
        return;
    }
    //double minKey = Heap->A[0]->key;
    Heap->A[0] = Heap->A[Heap->size-1];
    Heap->size--;
    heapify(Heap, 0);
    //fprintf(stdout, "ExtractMin: %lf\n", minKey);
}
