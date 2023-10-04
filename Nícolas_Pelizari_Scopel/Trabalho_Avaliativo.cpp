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

struct Ficha
{
    string nome;
    char sexo;
    char tipo;
    int quantidade;


    Ficha ()
    {
        nome = "";
        sexo = ' ';
        tipo = ' ';
        quantidade = 0;
    }

    Ficha (string n, char s, char t, int q)
    {
        nome = n;
        sexo = s;
        tipo = t;
        quantidade = q;
    }
};


#include "include/fila-dinamica-structficha.hpp"


int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha, nome, qual;
    Fila F1;
    Fila F2;
    char sexo,tipo;
    int quantidade, verifica  = 1;
    Ficha x;
    int cont = 0;


    ifstream arq ("entrada2.txt");

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

        if(op == "ADDFILA")
        {
            cout << "\n" << ++cont;
            strBuffer >> nome;
            strBuffer >> sexo;
            strBuffer >> tipo;
            strBuffer >> quantidade;

            int contF1 = contaF(&F1);
            int contF2 = contaF(&F2);

            if(quantidade < 1)
            {
                cout << "\nErro:" << nome << " não foi enfileirado(a). Não há itens para serem doados.";
            }

            else if(buscaFnome(&F1,nome) == false && buscaFnome(&F2,nome) == false)
            {
                if(quantidade > 10 && (contF1 - contF2)<3)
                {
                    enfileiraF(&F1,Ficha(nome,sexo,tipo,quantidade));
                    cout  << "\n"<< nome << " (qtd = " << quantidade << ") foi adicionado (a) na fila F1";

                }
                else if(quantidade < 10 && (contF2 - contF1) >= 3)
                {
                    enfileiraF(&F1, Ficha(nome,sexo,tipo,quantidade));
                    cout  << "\n"<< nome << " (qtd = " << quantidade << ") foi adicionado (a) na fila F1";


                }
                else
                {
                    enfileiraF(&F2, Ficha(nome,sexo,tipo,quantidade));
                    cout  << "\n"<< nome << " (qtd = " << quantidade << ") foi adicionado (a) na fila F2";

                }

            }
            else
            {
                cout << "\nERRO: " << nome << " já está em uma fila!";
            }


        }
        else if(op == "MOSTRAFILAS")
        {
              cout << "\n" << ++cont;
            if(vaziaF(&F1))
            {
                cout << "\nFila F1: Vazia";
            }
            else
            {
                cout << "\nFila F1: ";
                mostraF(&F1);


            }

            if(vaziaF(&F2))
            {
                cout << "\nFila F2: Vazia";
            }
            else
            {
                cout << "\nFila F2: ";
                mostraF(&F2);

            }



        }
        else if(op == "MOSTRAFILAORD")
        {
              cout << "\n" << ++cont;
            strBuffer >> qual;

            if(qual == "F1")
            {
                if(vaziaF(&F1))
                {
                    cout << "\nFila F1 Ordenada: vazia!";

                }
                else
                {

                }

            }
            else if(qual == "F2")
            {
                if(vaziaF(&F2))
                {
                     cout << "\nFila F2 Ordenada: vazia!";
                }
                else
                {

                }

            }


        }
        else if(op == "MOSTRADADOSFILAS")
        {
              cout << "\n" << ++cont;
            float pessoas = 0, totallivros = 0, totalroupas = 0, totalhomens = 0;
            float percentmasc = 0;

            if(vaziaF(&F1) && vaziaF(&F2))
            {
                cout.precision(2);
            cout << fixed;
            cout << "\nQuantidade de pessoas: " << 0 << "; Percentual do sexo M: " << 0 << "%; Quantidade de livros: " << 0 << "; Quantidade de roupas: " << 0;

            }
            else
            {
            pessoas = contaF(&F1);
            pessoas += contaF(&F2);
            totallivros = contaFLivros(&F1);
            totallivros += contaFLivros(&F2);
            totalroupas = contaFRoupas(&F1);
            totalroupas += contaFRoupas(&F2);
            totalhomens = contaFHomens(&F1);
            totalhomens += contaFHomens(&F2);
            percentmasc = (100 * totalhomens) / pessoas;

            cout.precision(2);
            cout << fixed;
            cout << "\nQuantidade de pessoas: " << pessoas << "; Percentual do sexo M: " << percentmasc << "%; Quantidade de livros: " << totallivros << "; Quantidade de roupas: " << totalroupas;
            }



        }

        else if(op == "MOSTRAMENORQTD")
        {
              cout << "\n" << ++cont;
            strBuffer >> sexo;

            if(vaziaF(&F1) && vaziaF(&F2))
            {
                cout << "\nERRO: Filas Vazias!";
            }
            else if(sexo == 'F')
            {
                string nome;
                int qtd;

                procuraMenorFem(&F1, &F2, &nome, &qtd);

            }

            else if(sexo == 'M')
            {
                string nome = "";
                int qtd = 0;

                procuraMenorMasc(&F1, &F2, &nome, &qtd);

            }
        }
        else if(op == "REMOVEFILA")
        {

              cout << "\n" << ++cont;
            if(vaziaF(&F1) && vaziaF(&F2))
            {
                cout << "\nERRO: Filas Vazias!";
            }
            else if(!vaziaF(&F1) && verifica == 1)
            {
                x = desenfileiraF(&F1);
                cout << "\n" << x.nome << " foi atendido na fila F1.";
                verifica = 2;

            }
            else if(!vaziaF(&F2) && verifica == 2)
            {
                x = desenfileiraF(&F2);
                cout << "\n" << x.nome << " foi atendido na fila F2.";
                verifica = 1;

            }
            else if(!vaziaF(&F1) && vaziaF(&F2) && verifica != 1)
            {
                x = desenfileiraF(&F1);
                cout << "\n" << x.nome << " foi atendido na fila F1.";
                verifica = 2;

            }
            else if(vaziaF(&F1) && !vaziaF(&F2) && verifica != 2)
            {
                x = desenfileiraF(&F2);
                cout << "\n" << x.nome << " foi atendido na fila F2.";
                verifica = 1;

            }

        }

        usleep(20000);

    }

    return 0;
}


