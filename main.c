#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{

    Quizz *start=incarcaFisier("intrebari.txt");

    if(start==NULL)
    {
        printf("Eroare la incarcarea fisierului");
        return 1;
    }

    quizz(start);

    return 0;
}