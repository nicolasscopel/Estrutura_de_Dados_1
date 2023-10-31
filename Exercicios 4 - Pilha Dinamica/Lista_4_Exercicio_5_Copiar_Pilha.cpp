/* 5. Crie uma função para copiar os dados pilha P1 para P2. Esta função deve preservar os dados armazenados em P1,
ou seja, após a execução da função, P1 e P2 devem possuir os mesmos elementos e na mesma ordem
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/pilha-dinamica.hpp"

void copiaP(Pilha *p1, Pilha *p2)
{
    Pilha aux;
    int valor;

    while(!vaziaP(p1))
    {
        valor = desempilhaP(p1);
        empilhaP(&aux, valor);
    }

    while(!vaziaP(&aux))
    {
        valor = desempilhaP(&aux);
        empilhaP(p1, valor);
        empilhaP(p2, valor);
    }

    destroiP(&aux);

}



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");


    Pilha p1;
    Pilha p2;
    int valor, menu;

    do
    {

        system("cls");
        cout << "\n-------- MENU --------";
        cout << "\n0 - Sair             -";
        cout << "\n1 - Gerar Pilha P1   -";
        cout << "\n2 - Copiar Pilha     -";
        cout << "\n----------------------";
        cout << "\nSua Escolha: ";
        cin >> menu;

        switch(menu)
        {
        case 0:
        {
            system("cls");
            cout << "\nFinalizando Programa!" << endl;

            destroiP(&p1);
            destroiP(&p2);

            system("pause");
            break;
        }

        case 1:
        {
            destroiP(&p1);
            destroiP(&p2);

            system("cls");
            cout << "\nInforme quantos valores deseja que sejam empilhados automaticamente: ";
            cin >> valor;

            for(int i = 0; i < valor; i++)
            {
                empilhaP(&p1, rand() % 50);

            }
            mostraP(&p1);

            system("pause");
            break;

        }
        case 2:
        {
            destroiP(&p2);
            system("cls");
            cout << "\nCopiando valores de P1 para P2" << endl;

            copiaP(&p1, &p2);
            cout << "\nP1 ";
            mostraP(&p1);
            cout << "\nP2 ";
            mostraP(&p2);


            system("pause");
            break;

        }

        default:
        {
            system("cls");
            cout << "\nOpção Incorreta!";

            system("pause");
            break;

        }
        }

    }
    while(menu != 0 );



}
