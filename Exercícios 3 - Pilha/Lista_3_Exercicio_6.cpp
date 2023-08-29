/* 6. A conversão de um número decimal N (base 10) para binário (base 2) é realizada por sucessivas divisões de N por
2, em que o número binário é obtido pelos restos das divisões realizadas. Crie um programa para converter
número decimais em binários empregando uma pilha.

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

	int menu, valor, numero;
	int tam = 32;

	inicializaP(&p1,tam);


	do
	{
	    system("cls");

	    cout << "\n-------- MENU --------";
	    cout << "\n0 - Sair             -";
	    cout << "\n1 - Converter Número -";
	    cout << "\n----------------------";
	    cout << "\nSua Escolha: ";
	    cin >> menu;

	    switch(menu)
	    {
        case 0:
            {
                system("cls");

                cout << "\nPrograma Finalizado" << endl;

                system("pause");
                break;
            }

        case 1:
            {

                system("cls");
                inicializaP(&p1,tam);

                cout << "\nInforme um numero para converter para binário: ";
                cin >> numero;

                cout << "\n0 - LSD" << endl;

                while(numero != 0)
                {
                    valor = numero % 2;

                    numero = numero / 2;

                    empilhaP(&p1, valor);

                }
                mostraP(&p1);

                destroiP(&p1);

                system("pause");
                break;

            }
        default:
            {
                system("cls");

                cout << "\nOpção Inválida" << endl;

                system("pause");
                break;
            }





	    }




	}while(menu != 0);

}
