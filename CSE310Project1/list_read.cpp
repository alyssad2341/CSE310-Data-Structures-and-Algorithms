/*
Name: Alyssa Duranovic
ASUID: 1224512913
*/

#include "list_read.h"
#include "data_structures.h"
#include <stdio.h>

double listMax(LIST * List){
	//NODE* maxNode = List->head;
	NODE* currentNode = List->head;
	double maxVal = currentNode->key;
	while (currentNode != NULL){
		if(currentNode->key >= maxVal){
			maxVal = currentNode->key;
		}
		currentNode = currentNode->next;
		
	}
	return maxVal;
}

void listPrint(LIST * List){
	NODE* currentNode = List->head;
	while (currentNode != NULL){
		printf("%lf\n", currentNode->key);
		currentNode = currentNode->next;
	}
}
