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




#include "include/.hpp"


int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha, nome, qual;
    int quantidade, verifica  = 1;




    ifstream arq ("entrada.txt");

    if (!arq.is_open())
    {
        cout << "Erro: n�o foi poss�vel abrir o arquivo texto.\n";
        return 0;
    }

    while(!arq.eof())
    {
        linha = ""; //IMPORTANTE, sempre inicializar a string
        getline(arq, linha);
        strBuffer = stringstream(linha);
        strBuffer >> op;

        if(op == "")
        {


        }
        else if(op == "")
        {




        }
        else if(op == "")
        {



        }
        else if(op == "")
        {


        }

        else if(op == "")
        {

        }
        else if(op == "")
        {


        }

        usleep(20000);

    }

    return 0;
}


