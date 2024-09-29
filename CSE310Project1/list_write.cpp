/*
Name: Alyssa Duranovic
ASUID: 1224512913
*/

#include "list_write.h"
#include "data_structures.h"
#include <cstdlib>
#include <cstdio>

void listInsert(LIST * List, double val){
	NODE* newNode = (NODE*)malloc(sizeof(NODE));

        if(newNode == NULL){
                fprintf(stderr, "Error: Unable to allocate memory for Node\n");
                exit(1);
        }
	newNode->key = val;
    newNode->next = List->head;
	List->head = newNode;

}


void listAppend(LIST * List, double val){

	NODE* newNode = (NODE*)malloc(sizeof(NODE));

	if(newNode == NULL){
		fprintf(stderr, "Error: Unable to allocate memory for Node\n");
		exit(1);
	}

	newNode->key = val;
	newNode->next = NULL;
	if (List->head == NULL) {
		List->head = newNode;
	}
	else {
		NODE* currentNode = List->head;
		while (currentNode->next != NULL) {
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
	//printf("%lf ", newNode->key);
}

void listDelete(LIST * List, double val){
	NODE* currentNode = List->head;
	NODE* previousNode = NULL;
	while(currentNode != NULL){
		if(currentNode->key == val){
			if(previousNode != NULL){
				previousNode->next = currentNode->next;
			}else{
				List->head = currentNode->next;
			}
			free(currentNode);
			return;
		}
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	fprintf(stderr, "Error: Key was not found in List\n");		

}










