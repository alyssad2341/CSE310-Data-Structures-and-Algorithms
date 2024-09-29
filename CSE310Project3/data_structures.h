/*
Name: Alyssa Duranovic
ASUID: 1224512913
*/

#ifndef _data_structures_h
#define _data_structures_h 1

#include <iostream>

typedef struct TAG_VERTEX{
    int index;
    double key;
    int pi;
    int position;
    double d;
    char color;
}VERTEX;

typedef struct TAG_NODE{
    int index;
    int u;
    int v;
    double weight;
    TAG_NODE *next;
}NODE;

typedef struct TAG_ELEMENT {
    double key;
    int position;
}ELEMENT;

typedef struct TAG_HEAP {
    int capacity;
    int size;
    ELEMENT** A;
    //int heapifyCalls;
}HEAP;





#endif