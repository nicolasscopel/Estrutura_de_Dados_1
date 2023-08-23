#include <iostream>
using namespace std;

#include "pilha.hpp"

bool buscaValor(Pilha *p, int valor, int tamPilha)
{
    Pilha aux;
    inicializaP(&aux, tamPilha);
    int v;


    bool encontrou=false;
    while(! vaziaP(p))
    {
        v = desempilhaP(p);
        empilhaP(&aux, v);
        if(v== valor)
        {
            encontrou=true;
            break;
        }
    }

    while(! vaziaP(&aux))
    {
        v = desempilhaP(&aux);
        empilhaP(p, v);

    }

    destroiP(&aux);
    return encontrou;
}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    Pilha p1;
    int tamPilha = 10;
    inicializaP(&p1, tamPilha);
    for (int i=0; i<tamPilha; i++)
        empilhaP(&p1, rand()%100);


    mostraP(&p1);

    int valor;
    cout << "Informe o valor: ";
    cin >> valor;

    cout << buscaValor(&p1, valor, tamPilha) << endl;

    mostraP(&p1);

    //desalocar mem�ria
    destroiP(&p1);


    return EXIT_SUCCESS;

}//final do main

