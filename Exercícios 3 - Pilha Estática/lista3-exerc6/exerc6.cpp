#include <iostream>
using namespace std;

#include "pilha.hpp"

void mostraPBin(Pilha *p){

    for(int i = p->topo; i > p->base; i--)
        cout << p->dados[i];

    cout << endl;

}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    inicializaP(&p1, 50); //vai até 50 bits!

    int numero = 246;

    while(numero>=2)
    {
        empilhaP(&p1, numero%2);
        numero /= 2;
    }
    empilhaP(&p1, numero);

    mostraPBin(&p1);


    //desalocar memória
    destroiP(&p1);


    return EXIT_SUCCESS;

}//final do main

