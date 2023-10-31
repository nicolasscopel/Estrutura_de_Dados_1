/*

ENCONTRAR E REMOVER O MAIOR E MENOR ELEMENTOS
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/pilha.hpp"


main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    Pilha p;
    int menor;
    int maior;


    inicializaP(&p,10);

    /*
    empilhaP(&p,8);
    empilhaP(&p,9);
    empilhaP(&p,7);
    empilhaP(&p,5);
    empilhaP(&p,3);
    empilhaP(&p,6);
    empilhaP(&p,4);
    */

    empilhaP(&p,8);
    empilhaP(&p,9);
    empilhaP(&p,7);
    empilhaP(&p,9);
    empilhaP(&p,5);
    empilhaP(&p,3);
    empilhaP(&p,6);
    empilhaP(&p,3);
    empilhaP(&p,4);


    mostraP(&p);

    removeMaiorMenor(&p);


}
