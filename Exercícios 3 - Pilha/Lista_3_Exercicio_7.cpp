/* 7. Crie um programa para intercalar duas pilhas P1 e P2 conforme o exemplo abaixo. Note que as pilhas P1 e P2
possuem o mesmo tamanho, mas o número de elementos armazenados em cada uma é diferente.

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

    Pilha p1;
    Pilha p2;

    int tamp1 = 7, cont1;
    int tamp2 = 5, cont2;
    bool resultado;

    inicializaP(&p1, tamp1);
    empilhaP(&p1, 13);
    empilhaP(&p1, 11);
    empilhaP(&p1, 9);
    empilhaP(&p1, 7);
    empilhaP(&p1, 5);
    empilhaP(&p1, 3);
    empilhaP(&p1, 1);

    inicializaP(&p2, tamp2);
    empilhaP(&p2, 6);
    empilhaP(&p2, 4);
    empilhaP(&p2, 2);


    mostraP(&p1);
    mostraP(&p2);

    cont1 = contP(&p1, tamp1);
    cont2 = contP(&p2, tamp2);

    int tamp3 = cont1 + cont2;

    Pilha p3;
    inicializaP(&p3, tamp3);

    for(int i = 0; i < tamp3; i++)
    {
        int valor;

        if(!vaziaP(&p1))
        {
            valor = desempilhaP(&p1);
            empilhaP(&p3, valor);
        }
        else
        {
           continue;
        }

        if(!vaziaP(&p2))
        {
            valor = desempilhaP(&p2);
            empilhaP(&p3, valor);
        }
        else
        {
            continue;
        }

    }

    mostraP(&p3);

}
