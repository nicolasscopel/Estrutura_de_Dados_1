#include <iostream>
using namespace std;

#include "pilha.hpp"



int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1, p2, p3;
    inicializaP(&p1, 10);
    inicializaP(&p2, 10);
    inicializaP(&p3, 20);

    empilhaP(&p1, 5);
    empilhaP(&p1, 4);
    empilhaP(&p1, 3);
    empilhaP(&p1, 2);



    empilhaP(&p2, 50);
    empilhaP(&p2, 40);
    empilhaP(&p2, 30);

   // mostraP(&p1);
   // cout << endl;
   // mostraP(&p2);

    while(!vaziaP(&p1) && !vaziaP(&p2))
    {
        int v1 = desempilhaP(&p1);
        int v2 = desempilhaP(&p2);
        empilhaP(&p3, v1);
        empilhaP(&p3, v2);
    }

    /*while(!vaziaP(&p1))
    {
        int v1 = desempilhaP(&p1);
        empilhaP(&p3, v1);
    }

    while( !vaziaP(&p2))
    {
        int v2 = desempilhaP(&p2);
        empilhaP(&p3, v2);
    }*/

    mostraP(&p3);







    //desalocar memória
    destroiP(&p1);
    destroiP(&p2);
    destroiP(&p3);


    return EXIT_SUCCESS;

}//final do main

