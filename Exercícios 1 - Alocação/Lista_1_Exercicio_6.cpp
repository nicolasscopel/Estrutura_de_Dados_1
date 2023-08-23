/* 6) Crie um programa que contenha um vetor V inicialmente nulo e contenha um menu com as seguintes op��es:
� A op��o 1 deve solicitar o tamanho do vetor V para o usu�rio e passar o vetor V para uma fun��o por refer�ncia,
a qual deve gerar o vetor V no tamanho desejado com valores aleat�rios. Na fun��o, antes de alocar o vetor,
deve-se verificar se o mesmo j� est� alocado e a mem�ria deve ser liberada.
� A op��o 2 deve mostrar os valores do vetor (primeiramente, verifique se o vetor n�o � nulo).*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

void gerar(int **V, int qtd);
void mostrar(int **V, int qtd);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");


    int tam, menu;
    int *vetor = nullptr;


    do
    {
        system("cls");

        cout << "###### MENU DE OP��ES #####" << endl;
        cout << "0 - Sair"<< endl;
        cout << "1 - Gerar Vetor"<< endl;
        cout << "2 - Mostrar Vetor"<< endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);



        switch(menu)
        {
        case 0:

            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;

        case 1:
        {



            system("cls");

            cout << "\nInforme o tamanho do VETOR: ";
            cin >> tam;


            gerar(&vetor, tam);

            getchar();
            break;

        }

        case 2:
        {

            system("cls");
            mostrar(&vetor, tam);

            getchar();
            break;
        }

        default :
            system("cls");
            cout << "Op��o inv�lida.";
            getchar();
            break;

        }

    }
    while (menu  != 0);



}

void gerar(int **V, int qtd)
{




    if(*V != NULL)
        delete[] (*V);

    *V = new int[qtd];

    for (int i=0; i<qtd ; i++)
        (*V)[i] = rand()%100;

}

void mostrar(int **V, int qtd)
{
    if(*V == NULL)
    {
        cout << "\nVetor nao gerado!";


    }
    else
    {
        cout << "Vetor: [";
        for(int i = 0; i < qtd; i++)
        {
            cout << (*V)[i] << " ";
        }
        cout << "]" << endl;
    }



}

