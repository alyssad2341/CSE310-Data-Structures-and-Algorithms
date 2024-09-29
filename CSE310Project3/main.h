/*
Name: Alyssa Duranovic
ASUID: 1224512913
*/

#ifndef _main_h
#define _main_h 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "graph.h"
#include "data_structures.h"
#include "stack.h"
#include <cfloat>
#include <iomanip>

void addEdge(NODE**, int, int, int, double, char, int);
void printADJ(NODE**, int);
void printPath(Stack&, int, int);
void printLength(Stack&, int, int);


#endif