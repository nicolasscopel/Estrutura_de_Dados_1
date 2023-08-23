/* 3) Construa um programa que apresente um menu com as seguintes op��es:
a. Gerar vetor - alocar dinamicamente um vetor de 10 posi��es com valores aleat�rios
no intervalor de 20 a 50;
b. Mostrar vetor � mostrar os elementos do vetor;
c. Sair do programa.
Observa��es:
� Antes de apresentar o menu, inicialize o vetor como NULL (int *vetor =
NULL;)
� Para gerar um novo vetor, caso o vetor j� tenha sido alocado, deve-se
liberar mem�ria antes de alocar um novo:
If (vetor != NULL)
 // liberar mem�ria...
� Na op��o mostrar vetor, o vetor n�o pode ser nulo. */

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

main()
{
    srand(time(NULL));

    setlocale (LC_ALL, "Portuguese");


    int *vetor = NULL;

    char menu;

    do
    {
        system("cls");

        cout << "###### MENU DE OP��ES #####" << endl;
        cout << "a - Gerar Vetor"<< endl;
        cout << "b - Mostrar Vetor"<< endl;
        cout << "c - Sair do programa"<< endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);



        switch(menu)
        {
        case 'a':

            system("cls");

            if(vetor != NULL)
            {
                cout << "\nJa existe um vetor. O espaco sera liberado para alocacao de outro." << endl;

                delete[] vetor;
                vetor = new int[10];
                for(int i = 0; i < 10; i++)
                {
                    vetor[i] = rand() % 31 + 20;
                }
            }
            else
            {
                vetor = new int[10];

                for(int i = 0; i < 10; i++)
                {
                    vetor[i] = rand() % 31 + 20;
                }
            }
            cout << "\nVetor Gerado com sucesso!";

            getchar();
            break;

        case 'b':

            system("cls");

            if(vetor == NULL)
            {
                cout << "\nVetor nao gerado!";


            }
            else
            {
                cout << "Vetor: [";
                for(int i = 0; i < 10; i++)
            {
                cout << vetor[i] << " ";
            }
            cout << "]" << endl;
            }


            getchar();
            break;

        case 'c':

            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;

        default :
            system("cls");
            cout << "Op��o inv�lida.";
            getchar();
            break;

        }

    }
    while (menu  !='c');








}
