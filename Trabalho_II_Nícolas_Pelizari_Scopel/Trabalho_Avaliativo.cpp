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




#include "include/lista_dupla.hpp"


int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha, nome, qual, lista;
    int quantidade, verifica  = 1;
    char dado, ordem, inserec, aposc;

    Lista L1 = Lista();
    Lista L2 = Lista();
    Lista L3 = Lista();



    ifstream arq ("entrada2.txt");

    if (!arq.is_open())
    {
        cout << "Erro: nao foi possivel abrir o arquivo texto.\n";
        return 0;
    }

    while(!arq.eof())
    {
        linha = ""; //IMPORTANTE, sempre inicializar a string
        getline(arq, linha);
        strBuffer = stringstream(linha);
        strBuffer >> op;

        if(op == "inserir")
        {
            strBuffer >> lista;

            if(lista == "L1")
            {
                strBuffer >> quantidade;
                cout << "\nOs caracteres <";

                for(int i = 0; i < quantidade; i++)
                {
                    strBuffer >> dado;
                    insereFinalL(&L1,dado);
                    cout << dado;
                }

                cout << "> foram adicionados na lista L1";



            }
            if(lista == "L2")
            {
                strBuffer >> quantidade;

                cout << "\nOs caracteres <";


                for(int i = 0; i < quantidade; i++)
                {
                    strBuffer >> dado;
                    insereFinalL(&L2,dado);
                    cout << dado;
                }

                 cout << "> foram adicionados na lista L2";


            }
            if(lista == "L3")
            {
                strBuffer >> quantidade;

                cout << "\nOs caracteres <";

                for(int i = 0; i < quantidade; i++)
                {
                    strBuffer >> dado;
                    insereFinalL(&L3,dado);
                    cout << dado;
                }

                 cout << "> foram adicionados na lista L3";
            }


        }
        else if(op == "mostrar")
        {
            strBuffer >> lista;

            if(lista == "L1")
            {
                strBuffer >> ordem;

                if(vaziaL(&L1) == true)
                {
                    cout << "\nL1-" << ordem << "[0]: {VAZIA}";
                }
                else
                {
                    if(ordem == 'N')
                    {
                        cout << "\nL1-"<< ordem << "[" << L1.tamanho << "]: ";  mostraL(&L1);
                    }
                    else if(ordem == 'I')
                    {
                        cout << "\nL1-"<< ordem << "[" << L1.tamanho << "]: ";  mostrarInversoL(&L1);
                    }
                }
            }

            if(lista == "L2")
            {

                strBuffer >> ordem;

                if(vaziaL(&L2) == true)
                {
                    cout << "\nL2-" << ordem << "[0]: {VAZIA}";
                }
                else
                {
                    if(ordem == 'N')
                    {
                        cout << "\nL2-"<< ordem << "[" << L2.tamanho << "]: "; mostraL(&L2);
                    }
                    else if(ordem == 'I')
                    {
                        cout << "\nL2-"<< ordem << "[" << L2.tamanho << "]: "; mostrarInversoL(&L2);
                    }

                }

            }

            if(lista == "L3")
            {

                strBuffer >> ordem;

                if(vaziaL(&L3) == true)
                {
                    cout << "\nL3-" << ordem << "[0]: {VAZIA}";
                }
                else
                {
                    if(ordem == 'N')
                    {
                        cout << "\nL3-"<< ordem << "[" << L3.tamanho << "]: " ; mostraL(&L3);
                    }
                    else if(ordem == 'I')
                    {
                        cout << "\nL3-"<< ordem << "[" << L3.tamanho << "]: " ; mostrarInversoL(&L3);
                    }

                }

            }




        }
        else if(op == "substituir")
        {
            strBuffer >> lista;

            if(lista == "L1")
            {
                strBuffer >> quantidade;
                cout << "\nSubstituicao de L1 pelos caracteres <";
                destroiL(&L1);

                for(int i = 0; i < quantidade; i++)
                {
                    strBuffer >> dado;
                    insereFinalL(&L1,dado);
                    cout << dado;
                }

                cout << "> ";

            }

            if(lista == "L2")
            {
                strBuffer >> quantidade;
                cout << "\nSubstituicao de L2 pelos caracteres <";
                destroiL(&L2);

                for(int i = 0; i < quantidade; i++)
                {
                    strBuffer >> dado;
                    insereFinalL(&L2,dado);
                    cout << dado;
                }

                cout << "> ";

            }

            if(lista == "L3")
            {
                strBuffer >> quantidade;
                cout << "\nSubstituicao de L3 pelos caracteres <";
                destroiL(&L3);

                for(int i = 0; i < quantidade; i++)
                {
                    strBuffer >> dado;
                    insereFinalL(&L3,dado);
                    cout << dado;
                }

                cout << "> ";

            }






        }
        else if(op == "inserirCaractereApos")
        {
                strBuffer >> lista;

                if(lista == "L1")
                {
                    strBuffer >> inserec;
                    strBuffer >> aposc;
                    insereCaractereApos(&L1,inserec,aposc);
                    cout << "L1";
                }
                if(lista == "L2")
                {
                    strBuffer >> inserec;
                    strBuffer >> aposc;
                    insereCaractereApos(&L2,inserec,aposc);
                    cout << "L2";


                }
                if(lista == "L3")
                {
                    strBuffer >> inserec;
                    strBuffer >> aposc;
                    insereCaractereApos(&L3,inserec,aposc);
                    cout << "L3";

                }

        }

        else if(op == "contarOcorrencia")
        {
            contarOcorrenciaL(&L1,&L2);

        }
        else if(op == "inserirAntesPrimeiraOcorrencia")
        {
            inserirAntesPrimeiraOcorrencia(&L1,&L2,&L3);



        }

        usleep(20000);

    }

    return 0;
}


