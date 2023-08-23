/*5 - Faça um programa que cadastre em uma estrutura do tipo pilha vários números, sendo no máximo 6, ao remover
um número desta estrutura (desempilhado) o mesmo deve ser empilhado em outra pilha, conforme o critério: se
o número for par na pilha dos pares, se for ímpar na pilha dos ímpares. No menu de opções deve ter uma
alternativa para zerar as três pilhas, mostrar pilha inicial, a dos pares e a dos ímpares.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>


using namespace std;

#include "include/pilha.hpp"

main(void)
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    Pilha p1;
    Pilha par;
    Pilha impar;
    int tamPilha = 6, valor, menu;
    bool resultado;


    do
    {
        system("cls");
        cout << "------------- MENU --------------" << endl;
        cout << "0 - Sair                        -" << endl;
        cout << "1 - Inserir                     -" << endl;
        cout << "2 - Remover                     -" << endl;
        cout << "3 - Consultar Pilha Inicial     -" << endl;
        cout << "4 - Consultar Pilha Pares       -" << endl;
        cout << "5 - Consultar Pilha Impares     -" << endl;
        cout << "6 - Zerar Pilhas                -" << endl;
        cout << "---------------------------------" << endl;
        cout << "Sua Escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {

        case 0:
        {
            system("cls");
            cout << "Programa finalizado." << endl;
            system("pause");
            break;
        }

        case 1:
        {
            system("cls");

            resultado = verificaInicializacaoP(&p1);

            if(resultado == false)
            {

                inicializaP(&p1, tamPilha);
                cout << "\nPilha Inicial Criada." << endl;

            }

            resultado = verificaInicializacaoP(&par);

            if(resultado == false)
            {

                inicializaP(&par, tamPilha);
                cout << "\nPilha Par Criada." << endl;

            }

            resultado = verificaInicializacaoP(&impar);

            if(resultado == false)
            {

                inicializaP(&impar, tamPilha);
                cout << "\nPilha Impar Criada." << endl;

            }

            cout << "\nInforme um número para empilhar na pilha INICIAL: ";
            cin >> valor;

            resultado = empilhaP(&p1, valor);
            if(resultado == true)
            {
                cout << "O valor " << valor << " foi empilhado com sucesso!\n";
            }
            else
            {
                cout << "Não foi possível empilhar o valor " << valor <<"!\n";
                system("pause");
                break;
            }

            system("pause");
            break;

        }

        case 2:
        {
            system("cls");

            resultado = verificaInicializacaoP(&p1);

            if(resultado == false)
            {
                cout << "\nA pilha ainda nao foi criada." << endl;
                system("pause");
                break;
            }

            if(vaziaP(&p1) == true)
            {
                cout << "A pilha está vazia!\n";
                system("pause");
                break;
            }

            if(vaziaP(&p1)== false)
            {
                valor = desempilhaP(&p1);
                cout << "O valor desempilhado é " << valor << endl;
            }

            if(valor % 2 == 0)
            {
                resultado = empilhaP(&par, valor);
            if(resultado == true)
            {
                cout << "O valor " << valor << " foi empilhado na pilha dos pares com sucesso!\n";
            }

            }

            if(valor % 2 != 0)
            {
                resultado = empilhaP(&impar, valor);
            if(resultado == true)
            {
                cout << "O valor " << valor << " foi empilhado na pilha dos impares com sucesso!\n";
            }

            }



            system("pause");
            break;
        }

        case 3:
        {
            system("cls");
            resultado = verificaInicializacaoP(&p1);

            if(resultado == false)
            {
                cout << "\nA pilha ainda nao foi criada." << endl;
                system("pause");
                break;
            }

            mostraP(&p1);
            system("pause");
            break;

        }

        case 4:
        {
            system("cls");
            resultado = verificaInicializacaoP(&par);

            if(resultado == false)
            {
                cout << "\nA pilha ainda nao foi criada." << endl;
                system("pause");
                break;
            }

            mostraP(&par);
            system("pause");
            break;

        }

        case 5:
        {
            system("cls");
            resultado = verificaInicializacaoP(&impar);

            if(resultado == false)
            {
                cout << "\nA pilha ainda nao foi criada." << endl;
                system("pause");
                break;
            }

            mostraP(&impar);
            system("pause");
            break;

        }

        case 6:
        {

            system("cls");

            destroiP(&p1);
            inicializaP(&p1, tamPilha);

            destroiP(&par);
            inicializaP(&par, tamPilha);

            destroiP(&impar);
            inicializaP(&impar, tamPilha);

            cout << "\nPilhas Zeradas!" << endl;


            system("pause");
            break;

        }


















        }




    }
    while(menu != 0);


}
