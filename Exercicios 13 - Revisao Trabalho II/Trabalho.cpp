#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

using namespace std;




#include "include/lista_descritor.hpp"


int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    Lista L1 = Lista();
    Lista L2 = Lista();
    Lista aux = Lista();
    string op,lista,linha, listasub;
    char ordem;
    int quantidade, verifica  = 1,valor;
    float mediana;




    ifstream arq ("entrada.txt");

    if (!arq.is_open())
    {
        cout << "Erro: não foi possível abrir o arquivo texto.\n";
        return 0;
    }

    while(!arq.eof())
    {
        linha = ""; //IMPORTANTE, sempre inicializar a string
        getline(arq, linha);
        strBuffer = stringstream(linha);
        strBuffer >> op;

        if(op == "adiciona")
        {
            strBuffer >> lista;
            strBuffer >> valor;

            if(lista == "L1")
            {
                insereFimL(&L1,valor);

                cout << "\nO numero " << valor << " foi adicionado na lista L1.";
            }
            else if(lista == "L2")
            {
                insereFimL(&L2,valor);
                cout << "\nO numero " << valor << " foi adicionado na lista L2.";
            }


        }
        else if(op == "mostra")
        {
            strBuffer >> lista;
            strBuffer >> ordem;

            if(lista == "L1")
            {
                if(vaziaL(&L1))
                {
                    cout << "\n" << lista << "(" << ordem << "): VAZIA";
                }
                else
                {
                    if(ordem == 'I') ///ORDEM INSERIDO
                    {
                       cout << "\n" << lista << "(" << ordem << "):";
                         mostraL(&L1);
                    }
                    if(ordem == 'C') ///ORDEM CRESCENTE
                    {
                         cout << "\n" << lista << "(" << ordem << "):";
                         mostraLCrescente(&L1);

                    }
                    if(ordem == 'D')///ORDEM DECRESCENTE
                    {
                        cout << "\n" << lista << "(" << ordem << "):";
                        mostraLDecrescente(&L1);

                    }
                }

            }

            if(lista == "L2")
            {
                if(vaziaL(&L2))
                {
                    cout << "\n" << lista << "(" << ordem << "): VAZIA";
                }
                else
                {
                    if(ordem == 'I') ///ORDEM INSERIDO
                    {
                       cout << "\n" << lista << "(" << ordem << "):";
                         mostraL(&L2);
                    }
                    if(ordem == 'C') ///ORDEM CRESCENTE
                    {
                         cout << "\n" << lista << "(" << ordem << "):";
                         mostraLCrescente(&L2);

                    }
                    if(ordem == 'D')///ORDEM DECRESCENTE
                    {
                        cout << "\n" << lista << "(" << ordem << "):";
                        mostraLDecrescente(&L2);


                    }


                }


            }





        }
        else if(op == "mostraDif")
        {
            strBuffer >> listasub;

            if(listasub == "L1")
            {

                cout << "\nL1 - L2: ";
                if(vaziaL(&L1))
                {
                    cout << "VAZIA.";
                }
                else
                {
                     mostraDifL(&L1,&L2);
                }

            }

            if(listasub == "L2")
            {
                cout << "\nL2 - L1: ";
                if(vaziaL(&L2))
                {
                    cout << "VAZIA.";
                }
                else
                {
                      mostraDifL(&L2,&L1);
                }

            }


        }
        else if(op == "removeTodos")
        {

            strBuffer >> lista;

            if(lista == "L1")
            {
                removeTodos(&L1);
                cout << "\nTodos os valores de L1 foram removidos.";

            }
            if(lista == "L2")
            {
                removeTodos(&L2);
                cout << "\nTodos os valores de L1 foram removidos.";

            }


        }

        else if(op == "mediana")
        {
             strBuffer >> lista;

             if(lista == "L1")
             {
                 if(vaziaL(&L1))
                 {
                     cout << "\nErro ao calcular a mediana de L1: lista vazia! ";
                 }
                 else
                 {
                     mediana = verificaMedianaL(&L1);
                     cout.precision(2);
                     cout << fixed;
                     cout << "\nMediana L1: " << mediana;
                 }
             }

             if(lista == "L2")
             {
                 if(vaziaL(&L2))
                 {

                     cout << "\nErro ao calcular a mediana de L2: lista vazia! ";
                 }
                 else
                 {
                     mediana = verificaMedianaL(&L2);
                     cout.precision(2);
                     cout << fixed;
                     cout << "\nMediana L2: " << mediana;
                 }
             }

        }
        else if(op == "moda")
        {
            strBuffer >> lista;

            if(lista == "L1")
             {
                 if(vaziaL(&L1))
                 {
                     cout << "\nModa (s) L1: VAZIA! ";
                 }
                 else
                 {
                     cout << "\nModa (s) L1: ";

                 }
             }

             if(lista == "L2")
             {
                 if(vaziaL(&L2))
                 {

                     cout << "\nModa (s) L2: VAZIA! ";
                     verificaModaL(&L1);
                 }
                 else
                 {
                     cout << "\nModa (s) L2: ";
                     verificaModaL(&L2);

                 }

             }


        }

        usleep(20000);

    }

    return 0;
}


