/* 4. Empregando pilha, crie uma fun��o para verificar se uma express�o composta apenas por chaves, colchetes e
par�nteses est� ou n�o balanceada.
a) Exemplo de express�es balanceadas: [ { () () } {} ], { [ ( [ { } ] ) ] }
b) Exemplo de express�es n�o balanceadas: { [ ( } ] ), { [ ) () ( ] }
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

#include "include/pilha-dinamicachar.hpp"

void verificaexpressao(string valor, int tam)
{

    char c = ' ';
    char p = ' ';
    bool balanceado = true;
    Pilha p1;

    for(int i = 0; i < tam; i++)
    {
        if(valor[i] == '(')
        {
            empilhaP(&p1, valor[i]);
        }

        if(valor[i] == '[')
        {
            empilhaP(&p1, valor[i]);
        }

        if(valor[i] == '{')
        {
            empilhaP(&p1, valor[i]);
        }


        if(valor[i] == ')')
        {
            if(vaziaP(&p1))
            {
                balanceado = false;
                break;
            }

            p = espiaP(&p1);

            if(p == '(')
            {
                desempilhaP(&p1);
            }
            else
            {
                balanceado = false;
                break;

            }
        }

        if(valor[i] == ']')
        {
            if(vaziaP(&p1))
            {
                balanceado = false;
                break;
            }

            p = espiaP(&p1);

            if(p == '[')
            {
                desempilhaP(&p1);
            }
            else
            {
                balanceado = false;
                break;

            }
        }

        if(valor[i] == '}')
        {
            if(vaziaP(&p1))
            {
                balanceado = false;
                break;
            }

            p = espiaP(&p1);

            if(p == '{')
            {
                desempilhaP(&p1);
            }
            else
            {
                balanceado = false;
                break;

            }
        }

    }

    if(!vaziaP(&p1))
        balanceado = false;


mostraP(&p1);

    if(balanceado == true)
    {
        cout << "\nA express�o esta balanceada! ";

    }
    else
    {
        cout << "\nA express�o n�o esta balanceada! ";
    }

}



main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    string valor;
    int tam;



    cout << "\nInforme uma express�o para verificar: ";
    getline(cin,valor);
    tam = valor.size();

    verificaexpressao(valor,tam);

}
