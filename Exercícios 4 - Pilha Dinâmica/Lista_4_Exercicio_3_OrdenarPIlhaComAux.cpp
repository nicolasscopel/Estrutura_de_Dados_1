/* 3. Empregando pilha, construa um programa para ordenar uma sequência de valores inteiros fornecidos pelo
usuário. Faça uso de duas pilhas: ORD e AUX. O objetivo é organizar a pilha ORD de modo que nenhum item seja
empilhado sobre outro menor, fazendo uso da pilha auxiliar AUX.
a) O usuário pode informar quantos valores inteiros ele desejar.
b) Ao final, o programa deve mostrar a pilha ORD.
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


void empilhaPOrganizado(Pilha *ord, int num)
{
    int valor;
    Pilha aux;

    while(!vaziaP(ord) && ord->topo->dado < num)
    {
        valor = desempilhaP(ord);
        empilhaP(&aux, valor);
    }

    empilhaP(ord, num);

    while(!vaziaP(&aux))
    {
        valor = desempilhaP(&aux);
        empilhaP(ord, valor);
    }
}



main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    Pilha ord;

    int menu, valor;

    do
    {

        system("cls");
        cout << "\n-------- MENU --------";
        cout << "\n0 - Sair             -";
        cout << "\n1 - Empilhar Valor   -";
        cout << "\n2 - Mostrar ORD      -";
        cout << "\n----------------------";
        cout << "\nSua Escolha: ";
        cin >> menu;

        switch(menu)
        {
        case 0:
        {
            system("cls");
            cout << "\nPilha ORD:" << endl;

            mostraP(&ord);

            system("pause");
            break;
        }

        case 1:
        {
            system("cls");
            cout << "\nInforme um valor para empilhar: ";
            cin >> valor;

            empilhaPOrganizado(&ord,valor);

            system("pause");
            break;

        }
        case 2:
        {
            system("cls");

            mostraP(&ord);

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
