/**/

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
    int codigo;
    string nome;
    int idade;
    float saldo;

    Ficha ()
    {
        codigo = 0;
        nome = "";
        idade = 0;
        saldo = 0;
    }

    Ficha (int c, string n, int i, float s)
    {
        codigo = c;
        nome = n;
        idade = i;
        saldo = s;
    }
};

#include "include/pilha-dinamica-revisao.hpp"
#include "include/fila-dinamica-revisao.hpp"



void insereOrdenadoP(Pilha *p, Ficha f)
{
    Pilha aux;

    if(buscaViaCodigoP(p,f.codigo))
    {
        return;
    }

    while(!vaziaP(p) && p->topo->dado.nome < f.nome)
    {
        Ficha x = desempilhaP(p);
        empilhaP(&aux, x);

    }
    empilhaP(p,f);

    while(!vaziaP(&aux))
    {
        Ficha x = desempilhaP(&aux);
        empilhaP(p, x);

    }

}

int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha;
    int codigo, idade, valor, negativados = 0, cadastrados = 0;
    float saldo, soma = 0;
    string nome;
    char operacao;
    Pilha CADASTRO;
    Fila P;
    Fila N;
    Fila D;
    Ficha x;


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

        if(op == "CADASTRAR")
        {
            strBuffer >> codigo;
            strBuffer >> nome;
            strBuffer >> idade;
            strBuffer >> saldo;


            if(buscaViaCodigoP(&CADASTRO,codigo) == false)
            {
                insereOrdenadoP(&CADASTRO, Ficha(codigo,nome,idade,saldo));

                cout << "\n"<< nome << " (cod " << codigo << ") foi empilhado.";

            }
            else
            {
                cout << "\nERRO: já existe um cliente com o código " << codigo << " cadastrado.";
            }


        }
        else if(op == "MOSTRAR")
        {
            strBuffer >> operacao;

            if(operacao == 'P')
            {
                if(vaziaP(&CADASTRO))
                {
                    cout << "\nPilha: vazia";
                }
                else
                {
                    mostraP(&CADASTRO);
                }
            }

            if(operacao == 'F')
            {
                mostraFP(&P);
                mostraFN(&N);
                mostraFD(&D);
            }


        }
        else if(op == "ADDFILA")
        {
            strBuffer >> codigo;

            if(buscaViaCodigoP(&CADASTRO, codigo) == false)
            {
                cout << "\nERRO: Cliente Inexistente";

            }
            else
            {
                x = retiraDados(&CADASTRO, codigo);

                if(buscaF(&P, codigo) == true || buscaF(&N, codigo) == true || buscaF(&D, codigo) == true)
                {
                    cout << "\nERRO: " << x.nome << " já está na fila aguardando atendimento.";
                }

                else if(x.idade > 60)
                {
                    enfileiraF(&P, x.codigo);
                    cout << "\n" << x.nome <<" (cod " << x.codigo << ") foi adicionado(a) na fila P.";
                }
                else if(x.idade < 60 && x.saldo > 0)
                {
                    enfileiraF(&N, x.codigo);
                    cout << "\n" << x.nome <<" (cod " << x.codigo << ") foi adicionado(a) na fila N.";
                }
                else if(x.idade < 60 && x.saldo < 0)
                {
                    enfileiraF(&D, x.codigo);
                    cout << "\n" << x.nome <<" (cod " << x.codigo << ") foi adicionado(a) na fila D.";
                }


            }

        }
        else if(op == "ATENDENDERCLIENTE")
        {
            strBuffer >> operacao;
            strBuffer >> valor;

            if(vaziaF(&P) == true && vaziaF(&N) == true && vaziaF(&D) == true)
            {
                cout << "\nERRO: não há clientes nas filas. ";
            }
            else if(!vaziaF(&P))
            {
                if(operacao == 'S')
                {
                    soma = somaSaldo(&CADASTRO);

                    if(valor > soma * 0.80)
                    {
                        desenfileiraF(&P);
                        cout.precision(2);
                        cout << fixed;
                        cout << "\nERRO: Não foi possível realizar o saque do valor informado. O limite atual de saque é de R$ " << soma * 0.80;
                    }
                    else
                    {
                        codigo = desenfileiraF(&P);
                        x = retiraDados(&CADASTRO, codigo);

                        sacaViaCodigoP(&CADASTRO, codigo, valor);

                        cout.precision(2);
                        cout << fixed;
                        cout << "\n" << x.nome << " sacou R$ " << valor;
                    }
                }
                else if(operacao == 'D')
                {
                    codigo = desenfileiraF(&P);
                    x = retiraDados(&CADASTRO, codigo);

                    depositoViaCodigoP(&CADASTRO, codigo, valor);

                    cout.precision(2);
                    cout << fixed;
                    cout << "\n" << x.nome << " depositou R$ " << valor;
                }

            }
            else if(!vaziaF(&N))
            {
                if(operacao == 'S')
                {
                    soma = somaSaldo(&CADASTRO);

                    if(valor > soma * 0.80)
                    {
                        cout.precision(2);
                        cout << fixed;
                        desenfileiraF(&N);
                        cout << "\nERRO: Não foi possível realizar o saque do valor informado. O limite atual de saque é de R$ " << soma * 0.80;
                    }
                    else
                    {
                        codigo = desenfileiraF(&N);
                        x = retiraDados(&CADASTRO, codigo);

                        sacaViaCodigoP(&CADASTRO, codigo, valor);

                        cout.precision(2);
                        cout << fixed;
                        cout << "\n" << x.nome << " sacou R$ " << valor;
                    }
                }
                else if(operacao == 'D')
                {
                    codigo = desenfileiraF(&N);
                    x = retiraDados(&CADASTRO, codigo);

                    depositoViaCodigoP(&CADASTRO, codigo, valor);

                    cout.precision(2);
                    cout << fixed;
                    cout << "\n" << x.nome << " depositou R$ " << valor;
                }
            }

            else if(!vaziaF(&D))
            {
                if(operacao == 'S')
                {
                    soma = somaSaldo(&CADASTRO);

                    if(valor > soma * 0.80)
                    {
                        desenfileiraF(&D);
                        cout.precision(2);
                        cout << fixed;
                        cout << "\nERRO: Não foi possível realizar o saque do valor informado. O limite atual de saque é de R$ " << soma * 0.80;
                    }
                    else
                    {
                        codigo = desenfileiraF(&D);
                        x = retiraDados(&CADASTRO, codigo);

                        sacaViaCodigoP(&CADASTRO, codigo, valor);

                        cout.precision(2);
                        cout << fixed;
                        cout << "\n" << x.nome << " sacou R$ " << valor;
                    }
                }
                else if(operacao == 'D')
                {
                    codigo = desenfileiraF(&D);
                    x = retiraDados(&CADASTRO, codigo);

                    depositoViaCodigoP(&CADASTRO, codigo, valor);

                    cout.precision(2);
                    cout << fixed;
                    cout << "\n" << x.nome << " depositou R$ " << valor;
                }
            }
        }

        else if(op == "DADOSBANCO")
        {
            soma = somaSaldo(&CADASTRO);
            cadastrados = contaCadastrados(&CADASTRO);
            negativados = contaNegativados(&CADASTRO);

            float media;

            if(soma == 0 && cadastrados == 0)
            {
                media = 0;
            }
            else
            {
                media  = soma / cadastrados;
            }

            cout << "\nTotal Clientes: " << cadastrados << "; Clientes com saldo negativo: " << negativados;
            cout << "; Saldo médio: " << media << "; Soma dos Saldos: " << soma;


        }

        usleep(30000);

    }

    return 0;
}
