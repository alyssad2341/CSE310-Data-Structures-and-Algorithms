/*
Name: Alyssa Duranovic
ASUID: 1224512913
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

HEAP* init(int capacity){
    //fprintf(stdout, "capacity: %d\n", capacity);
    //HeapifyCalls = 0;
    HEAP *Heap;
    Heap = (HEAP *) calloc(1, sizeof(HEAP));
    if (!Heap){
        fprintf(stderr, "Error: calloc failed\n");
        return NULL;
    }
    Heap->capacity = capacity;
    Heap->size = 0;
    Heap->heapifyCalls = 0;
    Heap->A = (ELEMENT**)calloc(capacity, sizeof(ELEMENT*));
    if(!(Heap->A)){
        fprintf(stderr, "Error: calloc failed for array\n");
        free(Heap);
        return NULL;
    }
    //fprintf(stdout, "capacity: %d\n", Heap->capacity);
    //fprintf(stdout, "size: %d\n", Heap->size);
    return Heap;
}

void print(HEAP *Heap){
    fprintf(stdout, "%d\n", Heap->size);
    for(int i=0; i<Heap->size; i++){
        fprintf(stdout, "%lf\n", Heap->A[i]->key);
    }
}

void read(FILE *in_fp, HEAP *Heap){
    int size;
    fscanf(in_fp, "%d", &size);
    if(size>(Heap->capacity)){
        fprintf(stderr, "Error: reached maximum capacity\n");
        fclose(in_fp);
        return;
    }

    double key_val;

    for (int i = 0; i < Heap->size; i++) {
        free(Heap->A[i]);
    }
    free(Heap->A);

    Heap->size = 0;


    while(fscanf(in_fp, "%lf", &key_val)==1){
        ELEMENT *Element = (ELEMENT *)malloc(sizeof(ELEMENT));
        if (Element == NULL){
            fprintf(stderr, "Error: memory allocation failed for element\n");
            return;
        }
        Element->key = key_val;
        //printf("Read element key: %lf\n", Element->key);
        Heap->A[Heap->size] = Element;
        Heap->size++;
    }

    fclose(in_fp);
    BuildHeap(Heap);
    
}

void write(FILE *fp_out, HEAP *Heap){
    fprintf(fp_out, "%d\n", Heap->size);
    for(int i = 0; i<Heap->size; i++){
        fprintf(fp_out, "%f\n", Heap->A[i]->key);
    }
}



int main(int argc, char **argv){

    FILE *fp;
    FILE *fp_out;
    HEAP *Heap = NULL;
    double value1, value2;
    int returnV;
    char Word[100];
    //int heapFlag = 0;

    if (argc != 4){
        fprintf(stderr, "Usage: ./PJ2 <ifile> <ofile> flag\n");
        return 0;
    }
    if ((strcmp(argv[3], "1")!=0) && (strcmp(argv[3], "0"))!=0){
        fprintf(stderr, "Usage: ./PJ2 <ifile> <ofile> flag\n");
        return 0;
    }

    int flag = atoi(argv[3]);


    while (1){
        returnV = nextInstruction(Word, &value1, &value2);

        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction\n");
            continue;
        }

        if (strcmp(Word, "Init")==0){
            //if(heapFlag == 0){
                Heap = init(value1);
                //heapFlag = 1;
            //}else{
               //free the object allocated in the first memory allocation and also write an error message to stderr 
            //}
            continue;
        }

        if (strcmp(Word, "Stop")==0){
            return 0;
        }

        if (strcmp(Word, "Print")==0){
            if(Heap==NULL){
                fprintf(stderr, "Error: heap is NULL\n");
            }else{
                if(flag == 1){
                    if(Heap->heapifyCalls!=0){
                        fprintf(stdout, "Number of Heapify calls: %d\n", Heap->heapifyCalls);
                        Heap->heapifyCalls = 0;
                    }
                }
                print(Heap);
                Heap->heapifyCalls = 0;
                //fprintf(stdout, "Number of Heapify calls: %d\n", Heap->heapifyCalls);
            }
            continue;
        }

        if (strcmp(Word, "Read")==0){
            if(Heap==NULL){
                fprintf(stderr, "Error: heap is NULL\n");
            }else{
                fp = fopen(argv[1], "r");
                if (!fp){
                    fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
                    //exit(0);
                }else{
                    read(fp, Heap);
                }
            }
            continue;
        }

        if (strcmp(Word, "Write")==0){
            if(Heap==NULL){
                fprintf(stderr, "Error: heap is NULL\n");
            }else{
                fp_out = fopen(argv[2], "w");
                if (!fp_out){
                    fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
                }else{
                    write(fp_out, Heap);
                }
                fclose(fp_out);
            }
            continue;
        }

        if (strcmp(Word, "DecreaseKey")==0){
            if(Heap==NULL){
                fprintf(stderr, "Error: heap is NULL\n");
            }else{
                decreaseKey(value1-1, value2, Heap);
            }
            continue;
        }

        if (strcmp(Word, "Insert")==0){
            if(Heap==NULL){
                fprintf(stderr, "Error: heap is NULL\n");
            }else{
                insert(value1, Heap);
            }
            continue;
        }

         if (strcmp(Word, "ExtractMin")==0){
            if(Heap==NULL){
                fprintf(stderr, "Error: heap is NULL\n");
            }else{
                extractMin(Heap);
            }
            continue;
        }


    }

}
