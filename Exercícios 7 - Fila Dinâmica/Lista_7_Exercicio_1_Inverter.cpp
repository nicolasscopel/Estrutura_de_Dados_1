/*1. Dada uma fila dinâmica F, implemente uma função para inverter a ordem dos elementos F. Para inverter a ordem
dos elementos, faça uso de uma pilha dinâmica P.
O menu deve conter as seguintes opções:
− Incluir na fila
− Remover da fila
− Mostrar fila
− Inverter fila
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

#include "include/fila-dinamica.hpp"
#include "include/pilha-dinamica.hpp"

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    Fila f;
    Pilha p;

    int menu;
    int valor;

    do
    {
        system("cls");
        cout << "---------- MENU ----------" << endl;
        cout << "0 - Sair                 -" << endl;
        cout << "1 - Incluir na Fila      -" << endl;
        cout << "2 - Remover da Fila      -" << endl;
        cout << "3 - Mostrar Fila         -" << endl;
        cout << "4 - Inverter Fila        -" << endl;
        cout << "--------------------------" << endl;
        cout << "Sua Escolha: ";
        cin >> menu;

        switch(menu)
        {

        case 0:
        {
            system("cls");

            cout << "\nPrograma Finalizado\n";

            system("pause");
            break;

        }

        case 1:
        {
            system("cls");
            cout << "\nInforme um valor para enfileirar: ";
            cin >> valor;

            enfileiraF(&f,valor);

            cout << "\nO valor " << valor << " foi enfileirado na fila!\n";

            system("pause");
            break;

        }
        case 2:
        {
            system("cls");

            valor = desenfileiraF(&f);

            cout << "\nO valor " << valor << " foi desenfileirado da fila!\n";


            system("pause");
            break;


        }
        case 3:
        {
            system("cls");

            mostraF(&f);

            system("pause");
            break;


        }
        case 4:
        {
            system("cls");
            if(vaziaF(&f))
            {
                cout << "\nFila Vazia!\n";
                system("pause");
                break;
            }

            while(!vaziaF(&f))
            {
                valor = desenfileiraF(&f);
                empilhaP(&p,valor);
            }

            while(!vaziaP(&p))
            {
                valor = desempilhaP(&p);
                enfileiraF(&f,valor);
            }

            cout << "\nFila Invertida!\n";


            system("pause");
            break;


        }

        default:
        {
            system("cls");

            cout << "\nOpcao Incorreta!\n";

            system("pause");
            break;
        }




        }


    }
    while(menu != 0);


}
