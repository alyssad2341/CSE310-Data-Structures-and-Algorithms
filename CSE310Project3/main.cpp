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
#include <cfloat>
#include <iomanip>



void addEdge(NODE** ADJ, int index, int u, int v, double w, char graphType, int flag) {
    NODE* node = new NODE;
    node->index = index;
    node->u = u;
    node->v = v;
    node->weight = w;
    node->next = nullptr;

    if (graphType == 'd') {
        if (flag == 1) {
            node->next = ADJ[u];
            ADJ[u] = node;
        } else if (flag == 2) {
            NODE* current = ADJ[u];
            if (current == nullptr) {
                ADJ[u] = node;
            } else {
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = node;
            }
        }
    } else if (graphType == 'u') {
        if (flag == 1) {
            node->next = ADJ[u];
            ADJ[u] = node;

            NODE* nodeV = new NODE;
            nodeV->index = index;
            nodeV->u = v;
            nodeV->v = u;
            nodeV->weight = w;
            nodeV->next = ADJ[v];
            ADJ[v] = nodeV;
        } else if (flag == 2) {
            NODE* nodeU = new NODE;
            nodeU->index = index;
            nodeU->u = u;
            nodeU->v = v;
            nodeU->weight = w;
            nodeU->next = nullptr;

            NODE* currentU = ADJ[u];
            if (currentU == nullptr) {
                ADJ[u] = nodeU;
            } else {
                while (currentU->next != nullptr) {
                    currentU = currentU->next;
                }
                currentU->next = nodeU;
            }

            NODE* nodeV = new NODE;
            nodeV->index = index;
            nodeV->u = v;
            nodeV->v = u;
            nodeV->weight = w;
            nodeV->next = nullptr;

            NODE* currentV = ADJ[v];
            if (currentV == nullptr) {
                ADJ[v] = nodeV;
            } else {
                while (currentV->next != nullptr) {
                    currentV = currentV->next;
                }
                currentV->next = nodeV;
            }
        }
    }
}

void printADJ(NODE** ADJ, int n){
    for (int i = 0; i < n; ++i) {
        std::cout << "ADJ[" << i + 1 << "]:";
        NODE* current = ADJ[i];
        while (current != nullptr) {
            std::cout << "-->[" << current->u+1 << " " << current->v+1 << ": " << std::fixed << std::setprecision(2) << current->weight << "]";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

void printPath(Stack& myStack, int val1, int val2){
    std::cout << "The shortest path from " << val1 << " to " << val2 << " is:\n";
    while (!myStack.isEmpty()) {
            VERTEX* vertex = myStack.pop();
            printf("[%d:%8.2lf]", vertex->index + 1, vertex->key);
            if(!myStack.isEmpty()){
                printf("-->");
            }else{
                printf(".\n");
            }
    }
    
}

void printLength(Stack& myStack, int val1, int val2){
    std::cout << "The length of the shortest path from " << val1 << " to " << val2 << " is:";
    double length;
    while (!myStack.isEmpty()) {
            VERTEX* vertex = myStack.pop();
            length = length + vertex->key;
    }
    printf("%8.2lf\n", length);
    
}


int main(int argc, char **argv){
    FILE *fp;
    FILE *fp_out;
    char graphType;
    int flag;
    int returnV = 1;
    int index;
    int u;
    int v;
    double w;
    

    if (argc != 4){
        fprintf(stderr, "Usage: ./PJ3 <InputFile> <GraphType> <Flag>\n");
        return 0;
    }

    if ((strcmp(argv[2], "DirectedGraph")!=0) && (strcmp(argv[2], "UndirectedGraph"))!=0){
        fprintf(stderr, "Usage: ./PJ3 <InputFile> <GraphType> <Flag>\n");
        return 0;
    }

    if ((strcmp(argv[3], "1")!=0) && (strcmp(argv[3], "2"))!=0){
        fprintf(stderr, "Usage: ./PJ3 <InputFile> <GraphType> <Flag>\n");
        return 0;
    }

    flag = atoi(argv[3]);

    //printf("%d\n", flag);

    fp = fopen(argv[1], "r");
    if (!fp){
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        return 0;
    }

    if (strcmp(argv[2], "DirectedGraph")==0){
        graphType = 'd';
    }else{
        graphType = 'u';
    }

    //printf("%c\n", graphType);

    int n;
    int m;

    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &m);

    //printf("n: %d\n", n);
    //printf("m: %d\n", m);

    VERTEX** V = new VERTEX*[n];
    for(int i = 0; i<n; i++){
        V[i] = new VERTEX;
    }

    NODE** ADJ = new NODE*[n];
    for(int i = 0; i<n; i++){
        ADJ[i] = nullptr;
    }

    double** weightsArray = new double*[n];
    for (int i = 0; i < n; ++i) {
        weightsArray[i] = new double[n];
    
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            weightsArray[i][j] = 0;
        }
    }

    while(returnV == 1){
        returnV = nextInstruction(fp, &index, &u, &v, &w);
        index--;
        u--;
        v--;

        if(returnV == 1){

            // printf("i: %d\n", index);
            // printf("u: %d\n", u);
            // printf("v: %d\n", v);
            // printf("w: %lf\n", w);

            addEdge(ADJ, index, u, v, w, graphType, flag);
            weightsArray[u][v] = w;
            if (graphType == 'u') {
                weightsArray[v][u] = w;
            }
        }
        continue;
    }

    Stack myStack(n);


    HEAP* Heap = new HEAP;
    Heap->size = n;
    Heap->capacity = n;
    Heap->A = new ELEMENT*[n];
    for(int i=0; i<n; i++){
        Heap->A[i] = new ELEMENT;
        Heap->A[i]->key = 0;
        Heap->A[i]->position = i;
    }

   char Word[100];
   int value1;
   int value2; 

   int source;
    int dest = -1;

    while (1){

    
        returnV = nextCommand(Word, &value1, &value2);
        

        if (returnV == 0){
            fprintf(stderr, "Invalid instruction\n");
            continue;
        }


        if (strcmp(Word, "Stop")==0){
            return 0;
        }

        if (strcmp(Word, "PrintADJ")==0){
            printADJ(ADJ, n);
            continue;
        }

        if (strcmp(Word, "SinglePair")==0){
            source = value1;
            dest = value2;
            source--;
            dest--;

            // printf("source: %d\n", source);
            // printf("dest: %d\n", dest);

            // for (int i = 0; i < n; ++i) {
            //     for (int j = 0; j < n; ++j) {
            //         printf("%8.2lf ", weightsArray[i][j]);
            //     }
            //     printf("\n");
            // }


            DijkstraSinglePair(ADJ, weightsArray, n, source, dest, Heap, myStack);
            continue;
        }

        if (strcmp(Word, "PrintLength")==0){
            source++;
            dest++;
            if(value1 == source && (dest == -1 || value2==dest) && !myStack.isEmpty()){
                if(dest == -1){
                    DijkstraSinglePair(ADJ, weightsArray, n, source, value2, Heap, myStack);
                }
                printLength(myStack, value1, value2);
            }else{
                std::cout << "There is no path from " << value1 << " to " << value2 << ".\n";
            }
            continue;
        }

        if (strcmp(Word, "PrintPath")==0){
            source++;
            dest++;
            if(dest == -1){
                    DijkstraSinglePair(ADJ, weightsArray, n, source, value2, Heap, myStack);
                }
            if(value1 == source && (dest == -1 || value2==dest) && !myStack.isEmpty()){
                printPath(myStack, value1, value2);
            }else{
                std::cout << "There is no path from " << value1 << " to " << value2 << ".\n";
            }
            continue;
        }

        if (strcmp(Word, "SingleSource")==0){
            source = value1;
            dest = -1;
            source--;
            for(int d =0; d<n; d++){
                DijkstraSingleSource(ADJ, weightsArray, n, source, d, Heap, myStack);
            }
            continue;
        }

    }
    

}