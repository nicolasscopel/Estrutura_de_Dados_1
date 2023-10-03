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

#include "include/pilha-dinamica.hpp"
#include "include/pilha-dinamica-structficha.hpp"
#include "include/fila-dinamica.hpp"
#include "include/fila-dinamica-structficha.hpp"


int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha;


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

        if(op == "OPERACAO_1")
        {

        }
        else if(op == "OPERACAO_2")
        {

        }
        else if(op == "OPERACAO_3")
        {

        }

        usleep(20000);

    }

    return 0;
}
