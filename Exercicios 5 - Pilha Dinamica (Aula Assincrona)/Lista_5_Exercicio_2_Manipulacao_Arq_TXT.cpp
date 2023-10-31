/* Implemente um programa que manipule uma pilha dinâmica P. O programa deve ler o arquivo entrada.txt e
realizar as operações:
o Inserir(V) – Inserir o valor V na pilha P e imprimir “O valor V foi inserido na pilha”.
o Remover() – Remover um elemento da pilha P e imprimir “O elemento X foi removido da pilha.’
Caso a pilha esteja vazia, imprimir a mensagem “PILHA VAZIA”.
o Consultar(V) – Verificar se V está armazenado na pilha. Imprimir “O valor V está armazenado na
pilha” ou “O valor V não está armazenado na pilha”.
o Mostrar() – Mostar os elementos da pilha. Caso a pilha esteja vazia, imprimir “PILHA VAZIA”.
o RemoverTodos() – Remove todos os elementos da pilha e imprimir “Todos os elementos
removidos.”
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;


#include "include/pilha-dinamica.hpp"

ifstream arq ("entrada.txt");

void mostraPexerc2(Pilha *p)
{

    if(vaziaP(p) == false)
    {
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            no;
             no->prox;
            cout  << no->dado << ", ";

            no = no->prox;
        }

    }
}

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    if (!arq.is_open())
    {
        cout << "Informe o nome do arquivo corretamente!\n";
        return 0;
    }

    Pilha p1;
    string operacao;
    int valor;


    while(!arq.eof())
    {
        if(!(arq >> operacao) || operacao.size()<=0)
            break;
        //arq >> operacao;
        //cout << operacao << endl;



        if(operacao == "INSERIR")
        {
            arq >> valor;
            empilhaP(&p1,valor);
            cout << "O valor "<< valor  <<" foi inserido na pilha" << endl;
        }

        else if(operacao == "REMOVER")
        {
            if(!vaziaP(&p1))
            {
                valor = desempilhaP(&p1);
                cout << "O elemento "<< valor  <<" foi removido na pilha" << endl;
            }
            else
            {
                cout << "PILHA VAZIA" << endl;
            }

        }
        else if(operacao == "CONSULTAR")
        {
            arq >> valor;
            if(buscaP(&p1, valor))
            {

                cout << "O valor "<< valor  <<" está armazenado na pilha" << endl;
            }
            else
            {
                cout << "O valor "<< valor  <<" não está armazenado na pilha" << endl;
            }

        }
        else if(operacao == "MOSTRAR")
        {
            if(!vaziaP(&p1))
            {
                mostraPexerc2(&p1);
                cout << endl;
            }
            else
            {
                cout << "PILHA VAZIA" << endl;
            }
        }

        else if(operacao == "REMOVERTODOS")
        {
            while(!vaziaP(&p1))
            {
                desempilhaP(&p1);

            }
            cout << "Todos elementos removidos " << endl;

        }




    }












}
