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

Quizz *incarcaFisier(char *fisier)
{
    FILE *f=fopen(fisier,"r");
    if(!f)
    {
        perror("Eroare");
        return NULL;
    }
    Quizz *noduri[100]={0};
    int stg[100];
    int drt[100];
    int id, st, dr,rezultat;
    char text[MAX_INTR], r1[MAX_RASP], r2[MAX_RASP],c;
    while(1)
    {
        rezultat=fscanf(f, "%d;%[^;];%[^;];%[^;];%d;%d\n", &id, text, r1, r2, &st, &dr);
        
        if(rezultat==-1)
        {
            break;
        }
        else if(rezultat==6)
        {
            printf("Am citit intrebarea cu ID: %d\n", id);
            noduri[id]=creeareIntrebare(text,r1,r2);
            stg[id]=st;
            drt[id]=dr;
        }
        else{
            while((c=fgetc(f))!= '\n'&&c!=-1);
        }
       
    }
    fclose(f);
    for(int i=1;i<100;i++)
    {
        if(noduri[i])
        {
            noduri[i]->var1=noduri[stg[i]];
            noduri[i]->var2=noduri[drt[i]];
        }
    }
    return noduri[1];
}
