/* 2 - Empregando pilha, crie uma fun��o para verificar se uma express�o matem�tica composta apenas por par�nteses
est� ou n�o balanceada.
� Exemplo de express�es balanceadas: �(A+B)�, �((A+B)+(C+D))�
� Exemplo de express�es n�o balanceadas: �((A+B)�, �)A+B(�, �(A+B)) � (C + D�
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/pilhachar.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Pilha p1;
    int tamPilha, menu;
    bool resultado = true;
    string valor;
    char c = ' ';



	cout << "\nInforme uma express�o para ver se ela � balanceada: ";
	getline(cin, valor);

	tamPilha = valor.size();

	inicializaP(&p1, tamPilha);



    for(int i = 0; i < tamPilha; i++)
    {
           if(valor[i] == '(')
           {
               empilhaP(&p1, valor[i]);
           }

        if(valor[i] == ')')
        {
            if(vaziaP(&p1))
            {
                resultado = false;
                break;
            }
            else
            {
                desempilhaP(&p1);
            }


        }

    }


    if(!vaziaP(&p1))
        resultado = false;

if(resultado == true)
{
    cout << "\nA express�o esta balanceada! ";

}
else
{
    cout << "\nA express�o n�o esta balanceada! ";
}







}
