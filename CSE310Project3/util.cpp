/*
Name: Alyssa Duranovic
ASUID: 1224512913
*/

#include <stdio.h>
#include <string.h>
#include "util.h"



int nextInstruction(FILE *fp, int *i, int *u, int *v, double *w)
{

    if(fscanf(fp, "%d", i)==1){
        if(fscanf(fp, "%d", u)==1){
            if(fscanf(fp, "%d", v)==1){
                if(fscanf(fp, "%lf", w)==1){
                    return 1;
                }
            }   
        }
    }

    return 0;

}

int nextCommand(char *Word, int *value1, int *value2)
{
    int  returnV;

    fscanf(stdin, "%s", Word);

    if (strcmp(Word, "Stop")==0) return 1;
    if (strcmp(Word, "PrintADJ")==0) return 1;
    

    if (strcmp(Word, "SinglePair")==0){
        returnV = fscanf(stdin, "%d", value1);
        if (returnV == 1){
            returnV = fscanf(stdin, "%d", value2);
            if (returnV == 1) {
                return 1;
            }
        }

        while (getchar() != '\n');


        return 0;
    }

    if (strcmp(Word, "SingleSource")==0){
        returnV = fscanf(stdin, "%d", value1);
        if (returnV == 1){
            return 1;
        }else{
            return 0;
        }
    }

    if (strcmp(Word, "PrintLength")==0){
        returnV = fscanf(stdin, "%d", value1);
        if (returnV == 1) {
            returnV = fscanf(stdin, "%d", value2);
            if (returnV == 1) {
                return 1;
            }
        }
        return 0;
    }

    if (strcmp(Word, "PrintPath")==0){
        returnV = fscanf(stdin, "%d", value1);
        if (returnV == 1) {
            returnV = fscanf(stdin, "%d", value2);
            if (returnV == 1) {
                return 1;
            }
        }
        return 0;
    }

    return 0;
}