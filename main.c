#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{

    Quizz *start = creeareIntrebare("Ce limbaj de programare inveti acum?", "C", "Python");

    Quizz *q2_corect = creeareIntrebare("Corect! Si ce pointer folosim pentru fisiere?", "FILE*", "int*");
    
    Quizz *q2_gresit = creeareIntrebare("Python e fain, dar acum facem C. Vrei sa continuam?", "Da", "Nu");

    Quizz *win = creeareIntrebare("Felicitari! Ai trecut testul.", "Iesire", "Iesire");
    Quizz *game_over = creeareIntrebare("Joc terminat.", "Iesire", "Iesire");

    start->var1 = q2_corect; 
    start->var2 = q2_gresit;

    q2_corect->var1 = win;
    q2_corect->var2 = game_over;

    q2_gresit->var1 = win;
    q2_gresit->var2 = game_over;

    quizz(start);

    return 0;
}