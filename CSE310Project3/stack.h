/*
Name: Alyssa Duranovic
ASUID: 1224512913
*/

#ifndef _stack_h
#define _stack_h 1

#include "data_structures.h"

class Stack {
private:
    int head = -1;
    int maxSize;
    int mysize = 0;
    VERTEX* stackArray;

public:
    Stack(int capacity);
    ~Stack();
    void push(VERTEX* vertex);
    bool isEmpty();
    VERTEX *pop();
    VERTEX *peek();
    int getMaxSize() const;
    int getSize() const;
};

#endif