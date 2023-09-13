/* 2. Desenvolva um programa que permita gerenciar uma pista para descolagem de avi�es de um aeroporto. Para o
correto funcionamento desta pista � necess�rio que seja implementada uma fila com as seguintes funcionalidades:
a) N� de avi�es � espera de decolar.
b) Entrada de um novo avi�o para decolar (incluir na fila).
c) Descolagem de um avi�o (retirar da fila).
d) Listar todos os avi�es � espera para decolagem (mostrar fila).
e) Listar as caracter�sticas do pr�ximo avi�o a decolar (peek).
Observa��o: para cada avi�o s�o necess�rias as seguintes informa��es: c�digo do avi�o, n�mero de
passageiros, empresa.
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

struct aviao
{
    int codigo;
    int passageiros;
    string empresa;

    aviao ()
    {
        codigo = 0;
        passageiros = 0;
        empresa = "";
    }

    aviao (int c, int p, string e)
    {
        codigo = c;
        passageiros = p;
        empresa = e;
    }
};



#include "include/filacircularaviao.hpp"


main()
{

    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    Fila f1;
    inicializaF(&f1, 10);
    char menu;
    aviao x;

    enfileiraF(&f1, aviao(1,100,"TAM"));
    enfileiraF(&f1, aviao(2,1000,"AZUL"));


    do
    {
        system("cls");

        cout << "------------------------- MENU -------------------------" << endl;
        cout << "a - N� de avi�es � espera de decolar                   -" << endl;
        cout << "b - Entrada de um novo avi�o para decolar              -" << endl;
        cout << "c - Descolagem de um avi�o                             -" << endl;
        cout << "d - Avi�es � espera para decolagem                     -" << endl;
        cout << "e - Caracter�sticas do pr�ximo avi�o a decolar         -" << endl;
        cout << "f - Sair                                               -" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Sua escolha: ";
        cin >> menu;


        switch(menu)
        {

        case 'a':
        {
            system("cls");



             cout << "\nAtualmente existem "<< f1.total << " avi�es a espera para decolar!" << endl;



            system("pause");
            break;

        }

        case 'b':
        {
            system("cls");

            int cod, pass;
            string nome;

            cout << "\nInforme o c�digo do avi�o: ";
            cin >> cod;

            cout << "\nInforme a quantidade de passageiros no avi�o: ";
            cin >> pass;

            cout << "\nInforme o nome da companhia: ";
            cin >> nome;

            enfileiraF(&f1, aviao(cod,pass,nome));


            system("pause");
            break;

        }

        case 'c':
        {
            system("cls");

            if(vaziaF(&f1))
            {
                cout << "\nFila de decolagem vazia!\n";
                system("pause");
                break;
            }

            x = desenfileiraF(&f1);

            cout << "\n--- O AVI�O DECOLOU --- " << endl;
            cout << "C�digo: " << x.codigo << endl;
            cout << "Passageiros: " << x.passageiros << endl;
            cout << "Companhia: " << x.empresa << endl;



            system("pause");
            break;

        }

        case 'd':
        {
            system("cls");

            mostraF(&f1);


            system("pause");
            break;

        }

        case 'e':
        {
            system("cls");



            system("pause");
            break;

        }

        case 'f':
        {
            system("cls");

            cout << "\nPrograma Finalizado com sucesso!" << endl;

            destroiF(&f1);

            system("pause");
            break;

        }


        }


    }
    while(menu != 'f');


}
