/*
Name: Alyssa Duranovic
ASUID: 1224512913
*/


#include <limits> 
#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "stack.h"
#include "heap.h"
#include <cfloat>
#include "data_structures.h"
#include <iostream>
#include <iomanip>



void DijkstraSingleSource(NODE** G, double** w, int n, int source, int dest, HEAP* Heap, Stack& myStack) {
    
    VERTEX* V = new VERTEX[n];

    for(int i = 0; i<n; i++){
        V[i].index = i;
        V[i].key = DBL_MAX;
        V[i].color = 'W';
        V[i].pi = -1;
        V[i].position = i;
    }
    V[source].key = 0;

    for(int i=0; i<n; i++){
        Heap->A[i]->key = V[i].key;
    }


    BuildHeap(Heap);

    while(Heap->size > 0){
        ELEMENT* u = Heap->A[0];
        extractMin(Heap);
        int indexU = u->position;


        if(V[indexU].color == 'W'){
            V[indexU].color = 'B';
            
            NODE* current = G[indexU];
            while(current != nullptr){
                int indexV = current->v;
                if(V[indexV].color == 'W' && V[indexV].key > V[indexU].key + w[indexU][indexV]){
                    V[indexV].key = V[indexU].key + w[indexU][indexV];
                    V[indexV].pi = indexU;
                    decreaseKey(V[indexV].position, V[indexV].key, Heap);
                }

                current = current->next;
            }
        }
    }


}



void DijkstraSinglePair(NODE** G, double** w, int n, int source, int dest, HEAP* Heap, Stack& myStack) {
   
    VERTEX* V = new VERTEX[n];

    for(int i = 0; i<n; i++){
        V[i].index = i;
        V[i].key = DBL_MAX;
        V[i].color = 'W';
        V[i].pi = -1;
        V[i].position = i;
    }
    V[source].key = 0;

    for(int i=0; i<n; i++){
        Heap->A[i]->key = V[i].key;
    }


    BuildHeap(Heap);

    while(Heap->size > 0){
        ELEMENT* u = Heap->A[0];
        extractMin(Heap);
        int indexU = u->position;


        if(V[indexU].color == 'W'){
            V[indexU].color = 'B';
            
            NODE* current = G[indexU];
            while(current != nullptr){
                int indexV = current->v;
                if(V[indexV].color == 'W' && V[indexV].key > V[indexU].key + w[indexU][indexV]){
                    V[indexV].key = V[indexU].key + w[indexU][indexV];
                    V[indexV].pi = indexU;
                    decreaseKey(V[indexV].position, V[indexV].key, Heap);
                }

                current = current->next;
            }
        }
    }



    if (V[dest].key < DBL_MAX) {

        int currentVertex = dest;
        while (currentVertex != -1) {
            myStack.push(&V[currentVertex]);
            int tempPosition = V[currentVertex].position;
            V[currentVertex].position = myStack.getSize() - 1;
            currentVertex = V[currentVertex].pi;

            if (V[currentVertex].position != tempPosition) {
                decreaseKey(tempPosition, V[currentVertex].key, Heap);
            }
        }

    }


    // delete[] V;
    // delete[] Heap->A;
    // delete Heap;
}