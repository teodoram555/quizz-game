#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Quizz *creeareIntrebare(char *intrb, char *rasp1, char *rasp2)
{
    Quizz *intrbNou = (Quizz *)malloc(sizeof(Quizz));
    if (intrbNou == NULL)
    {
        perror("Alocare esuata");
        exit(EXIT_FAILURE);
    }
    strcpy(intrbNou->intreabare, intrb);
    strcpy(intrbNou->raspuns1, rasp1);
    strcpy(intrbNou->raspuns2, rasp2);
    intrbNou->var1 = NULL;
    intrbNou->var2 = NULL;
    return intrbNou;
}
void quizz(Quizz *nod)
{
    if (nod == NULL)
    {
        exit(EXIT_FAILURE);
    }
    printf("Intrebare: %s\n", nod->intreabare);
    printf("1: %s\n", nod->raspuns1);
    printf("2: %s\n", nod->raspuns2);
    printf("Raspunsul ales: ");

    int raspuns;
    if(scanf("%d",&raspuns)!=1)
    {
        printf("Eroare\n");
        while(getchar()!='\n');
            quizz(nod);
        return;
    }
    if (raspuns == 1)
    {
        if (nod->var1 != NULL)
        {
            quizz(nod->var1);
        }
    }
    else if (raspuns == 2)
    {
        if (nod->var2 != NULL)
        {
            quizz(nod->var2);
        }
    }
    else
    {
        printf("Raspuns invalid");
        quizz(nod);
    }
}
