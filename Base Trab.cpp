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
    string op, linha, nome, qual;
    int quantidade, verifica  = 1;




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

        if(op == "adiciona")
        {


        }
        else if(op == "")
        {




        }
        else if(op == "")
        {



        }
        else if(op == "MOSTRADADOSFILAS")
        {


        }

        else if(op == "MOSTRAMENORQTD")
        {

        }
        else if(op == "REMOVEFILA")
        {


        }

        usleep(20000);

    }

    return 0;
}


