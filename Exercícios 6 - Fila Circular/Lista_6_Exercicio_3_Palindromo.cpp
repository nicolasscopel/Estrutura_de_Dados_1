/*3. Crie um programa para verificar se uma cadeia de caracteres é palíndroma. Uma cadeia é palíndroma se ela é igual
à sua inversa. Por exemplo, “ovo”, “arara” e “ata” são cadeias palíndromas. Faça uso de uma fila e de uma pilha
para implementar o programa.
Dica: Percorrer a cadeia de caracteres, inserindo cada caractere encontrado numa pilha e numa fila (em ambas
as estruturas). Posteriormente, para cada elemento armazenado na pilha e na fila, executar, respectivamente,
as operações de desempilhar e desenfileirar, comparando os caracteres retirados. Caso todos os caracteres
retirados forem iguais, a cadeia de caracteres é palíndroma.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

#include "include/filacircularchar.hpp"
#include "include/pilha-dinamicachar.hpp"

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    string palindromo;

    Fila f1;
    Pilha p1;
    int tam;
    char a, b;

    bool diferente = true;

    cout << "\nInforme uma palavra para verificação: ";
    getline(cin,palindromo);

    tam = palindromo.size();

    inicializaF(&f1, tam);

    for(int i = 0; i < tam; i++)
    {
        empilhaP(&p1, palindromo[i]);
        enfileiraF(&f1, palindromo[i]);
    }

    while(!vaziaP(&p1))
    {
        a = desempilhaP(&p1);
        b = desenfileiraF(&f1);

        if(a == b)
            continue;
            else
            {
                diferente = false;
                break;
            }
    }

    if(diferente)
    {
        cout << "\nEssa palavra é um palíndromo!";
    }
    else
    {
        cout << "\nEssa palavra não é um palíndromo!";
    }
}
