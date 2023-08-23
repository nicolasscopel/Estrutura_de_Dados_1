/*3. Desenvolva as seguintes funções:
• Função para testar se duas pilhas P1 e P2 são iguais.
Observação: Duas pilhas são iguais se elas possuem os mesmos elementos e na mesma ordem.
• Função para retornar o número de elementos da pilha que possuem valor par.
Observação: Use uma pilha auxiliar e as operações de empilha/desempilha para implementar as funções, ou
seja, não é permitido acessar o vetor da pilha diretamente (pilha->dados[i]).
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

int contaPares(Pilha *p, int tamPilha)
{
    Pilha aux;
    inicializaP(&aux, tamPilha);
    int v, cont = 0;


    while(! vaziaP(p))
    {
        v = desempilhaP(p);
        empilhaP(&aux, v);
        if(v % 2 == 0)
        {
            cont++;
        }


    }

    while(! vaziaP(&aux))
    {
        v = desempilhaP(&aux);
        empilhaP(p, v);

    }

    destroiP(&aux);
    return cont;
}

bool compara(Pilha *p1, Pilha *p2, int tamP1, int tamP2)
{
    int cP1 = contP(p1,tamP1);
    int cP2 = contP(p2,tamP2);
    int v1, v2;
    if(cP1 != cP2)
    {
        return false;
    }
    Pilha aux1;
    inicializaP(&aux1, tamP1);

    Pilha aux2;
    inicializaP(&aux2, tamP2);

    bool iguais = true;

    while(! vaziaP(p1))
    {
        v1 = desempilhaP(p1);
        empilhaP(&aux1, v1);
        v2 = desempilhaP(p2);
        empilhaP(&aux2, v2);

        if(v1 != v2)
        {
            iguais = false;
            break;
        }

    }



     while(! vaziaP(&aux1))
    {
        v1 = desempilhaP(&aux1);
        empilhaP(p1, v1);
        v2 = desempilhaP(&aux2);
        empilhaP(p2, v2);

        if(v1 != v2)
        {
            iguais = false;
            break;
        }

    }



}



main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    Pilha p1;
    Pilha p2;


    int tamp1 = 5, cont1;
    int tamp2 = 5, cont2;
    bool resultado;

    inicializaP(&p1, tamp1);
    //empilhaP(&p1, 5);
    //empilhaP(&p1, 5);
    //empilhaP(&p1, 2);



    for (int i=0; i<tamp1; i++)
    {
        empilhaP(&p1, rand() % 10);
    }


    inicializaP(&p2, tamp2);
    //empilhaP(&p2, 4);
    //empilhaP(&p2, 5);
    //empilhaP(&p2, 5);

    for (int i=0; i<tamp2; i++)
    {
        empilhaP(&p2, rand()% 10);
    }

    mostraP(&p1);
    mostraP(&p2);

    cont1 = contP(&p1, tamp1);
    cont2 = contP(&p2, tamp2);



    if(cont1 != cont2)
    {
        cout << "\nAs pilhas P1 e P2 NÃO são iguais pois possuem a quantidade de elementos diferentes! " << endl;


    }
    else
    {
        resultado = compara(&p1,&p2,cont1, cont2);

        if(resultado == false)
        {
            cout << "\nAs pilhas P1 e P2 NÃO são iguais pois possuem elementos diferentes! " << endl;
        }
        else
        {
            cout << "\nAs pilhas P1 e P2 são iguais! " << endl;
        }


    }
    int par = contaPares(&p1,cont1);
    int par2 = contaPares(&p2,cont2);

    cout << "\nQuantidade de pares na pilha P1: " << par;
    cout << "\nQuantidade de pares na pilha P2: " << par2;







}
