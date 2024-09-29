
/*
Name: Alyssa Duranovic
ASUID: 1224512913
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "graph.h"
#include "data_structures.h"
#include "stack.h"
#include <iomanip>



Stack::Stack(int capacity) {
    maxSize = capacity;
    int head = -1; 
    int mysize = 0;
    stackArray = new VERTEX[maxSize];
}

Stack::~Stack() {
    delete[] stackArray;
}

void Stack::push(VERTEX* vertex) {
    if (head < maxSize - 1) {
        stackArray[++head] = *vertex;
        mysize++;
    } else {
        fprintf(stderr, "Error: Stack Overflow\n");
    }
}

bool Stack::isEmpty() {
    return head == -1;
}

VERTEX* Stack::pop() {
    if (!isEmpty()) {
        mysize--;
        return &stackArray[head--];
    } else {
        fprintf(stderr, "Error: Stack is Empty\n");
        return nullptr;
    }
}

VERTEX* Stack::peek() {
    if (!isEmpty()) {
        return &stackArray[head];
    } else {
        fprintf(stderr, "Error: Stack is Empty\n");
        return nullptr;
    }
}

int Stack::getMaxSize() const {
    return maxSize;
}

int Stack::getSize() const {
    return mysize;
}