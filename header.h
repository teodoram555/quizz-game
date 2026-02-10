#ifndef HEADER_H_
#define HEADER_H_
#define MAX_INTR 100
#define MAX_RASP 50

typedef struct header
{
    char intreabare[MAX_INTR];
    char raspuns1[MAX_RASP];
    char raspuns2[MAX_RASP];
    struct header *var1;
    struct header *var2;
} Quizz;

Quizz *creeareIntrebare(char *intrb, char *rasp1, char *rasp2);
void quizz(Quizz *nod);

#endif