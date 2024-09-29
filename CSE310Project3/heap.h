/*
Name: Alyssa Duranovic
ASUID: 1224512913
*/

#ifndef _heap_h
#define _heap_h 1
#include "data_structures.h"

void BuildHeap(HEAP*);
void heapify(HEAP*, int);
void swap(ELEMENT**, ELEMENT**);
void decreaseKey(int, double, HEAP*);
void insert(double, HEAP*);
void extractMin(HEAP*);

#endif