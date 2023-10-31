/*  4. Crie um programa para converter número decimais em hexadecimais empregando uma pilha.
 */

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

#include "include/pilha-dinamicastring.hpp"

main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");


	Pilha p1;

	int menu, numero;
	int valor;
	string res;


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


                cout << "\nInforme um numero para converter para binário: ";
                cin >> numero;

                cout << "\n0 - LSD" << endl;

                while(numero != 0)
                {
                    valor = numero % 16;

                    numero = numero / 16;

                    if(valor == 0)
                    {
                         empilhaP(&p1, "0");
                    }
                    if(valor == 1)
                    {
                         empilhaP(&p1, "1");
                    }
                    if(valor == 2)
                    {
                         empilhaP(&p1, "2");
                    }
                    if(valor == 3)
                    {
                         empilhaP(&p1, "3");
                    }
                    if(valor == 4)
                    {
                         empilhaP(&p1, "4");
                    }
                    if(valor == 5)
                    {
                         empilhaP(&p1, "5");
                    }
                    if(valor == 6)
                    {
                         empilhaP(&p1, "6");
                    }
                    if(valor == 7)
                    {
                         empilhaP(&p1, "7");
                    }
                    if(valor == 8)
                    {
                         empilhaP(&p1, "8");
                    }

                    if(valor == 9)
                    {
                         empilhaP(&p1, "9");
                    }
                    if(valor == 10)
                    {
                        empilhaP(&p1, "A");
                    }
                    if(valor == 11)
                    {
                        empilhaP(&p1, "B");
                    }
                    if(valor == 12)
                    {
                        empilhaP(&p1, "C");
                    }
                    if(valor == 13)
                    {
                        empilhaP(&p1, "D");
                    }
                    if(valor == 14)
                    {
                        empilhaP(&p1, "E");
                    }
                    if(valor == 15)
                    {
                        empilhaP(&p1, "F");
                    }



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
