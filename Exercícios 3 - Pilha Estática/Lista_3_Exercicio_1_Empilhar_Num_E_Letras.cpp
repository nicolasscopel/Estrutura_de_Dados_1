/* 1. Faça um programa para ler uma string e após empilhar os caracteres que são letras em uma pilha P1 e empilhar
os que são dígitos em outra pilha P2. Ao final, desempilhe os dados de P2 e em seguida, os de P1, imprimindo-os
na tela.
Dicas:
− Use as funções isdigit e isalpha da biblioteca
− A pilha P1 deve armazenar letras. Dessa forma, altere o arquivo para atender esta
necessidade.
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

#include "include/pilhachar.hpp"



main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    Pilha p1;
    Pilha p2;
    string leitura;
    int tam;
    char c;


    cout << "\nInforme uma string para ser lida: ";
    getline(cin,leitura);



    tam = leitura.size();

    inicializaP(&p1,tam);
    inicializaP(&p2,tam);



    for(int i = 0; i < tam; i++)
    {
        if(isalpha(leitura[i]))
        {
            c = leitura[i];
            empilhaP(&p1, c);
        }

        if(isdigit(leitura[i]))
        {
            c = leitura[i];
            empilhaP(&p2, c);
        }
    }



    cout << "\nP2: ";
    while(!vaziaP(&p2))
    {
        cout << desempilhaP(&p2);
    }

    cout << "\nP1: ";
    while(!vaziaP(&p1))
    {

        cout << desempilhaP(&p1);
    }













}
