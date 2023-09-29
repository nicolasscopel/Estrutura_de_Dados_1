/* Construa um programa para gerenciar duas filas de impress�o de documentos, as filas P - Priorit�ria e N - N�o
Priorit�ria. Cada documento � composto pelas seguintes informa��es: nome, quantidade de p�ginas. A impress�o
dos documentos deve seguir a seguinte pol�tica de prioridade:
a) Quando a fila P n�o est� vazia, imprimir um documento que est� no in�cio da fila P.
b) Quando n�o h� documentos na Fila P, o documento que est� no in�cio da fila N deve ser impresso.
O programa deve ler o arquivo entrada.txt e realizar as opera��es:
o Inicializar (TAM) � Inicializa as filas P e N com o tamanho TAM recebido por par�metro.
o Mostrar (F) � Mostra os documentos da fila F. O par�metro F pode assumir os valores �P� ou �N�.
o Enfileirar (NOME, PAG, F) � Cria-se um novo documento com os par�metros NOME e PAG. O
documento criado deve ser enfileirado na fila F (o par�metro F pode assumir os valores �P� ou
�N�).
o ImprimirDoc() � Remove um documento de uma das filas com base na pol�tica de prioridade.
o TotalPag() � Imprimir a soma do n�mero de p�ginas de todos os documentos armazenados nas
filas.
o Consultar (NOME, F) � Consulta se o documento com nome NOME est� armazenado na fila F (o
par�metro F pode assumir os valores �P� ou �N�).
As opera��es citadas acima possuem as seguintes restri��es:
o Inicializar � Liberar mem�ria antes de inicializar as filas P e N (caso as filas j� tenham sido
inicializadas anteriormente).
o Mostrar � Mostrar a mensagem �ERRO: inicializar fila X� se a fila n�o foi inicializada; mostrar a
mensagem �FILA VAZIA� se a fila estiver vazia.
o Enfileirar� Mostrar a mensagem �ERRO: inicializar fila X� se a fila n�o foi inicializada; mostrar a
mensagem �FILA CHEIA� se a fila estiver cheia.
o ImprimirDoc � Mostrar a mensagem �ERRO: inicializar fila X� se a fila n�o foi inicializada; mostrar
a mensagem �N�O h� documentos para imprimir� se ambas as filas estiverem vazias.
o Consultar(V) � Mostrar a mensagem �ERRO: inicializar fila X� se a fila n�o foi inicializada; mostrar
a mensagem �FILA VAZIA� se a fila estiver vazia.
O programa deve imprimir na sa�da o resultado de cada opera��o especificada na entrada, um resultado por
linha. Um exemplo de entrada e sa�da � ilustrado no quadro abaixo.*/

#include <unistd.h>
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

struct Documentos
{
    string nome;
    int paginas;

    Documentos ()
    {

        nome = "";
        paginas = 0;
    }

    Documentos (string n, int p)
    {
        nome = n;
        paginas = p;
    }
};

#include "include/filacircular_impressao.hpp"

ifstream arq ("Entrada.txt");


main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    Documentos x;

    if (!arq.is_open())
    {
        cout << "Informe o nome do arquivo corretamente!\n";
        return 0;
    }


    string operacao;
    char tipo;
    string nome;
    int pag;
    int tam;

    Fila P;
    Fila N;


    while(!arq.eof())
    {
        if(!(arq >> operacao) || operacao.size()<=0)
            break;
        //arq >> operacao;
        //cout << operacao << endl;



        if(operacao == "ENFILEIRARDOC") ///FEITA
        {
            arq >> nome;
            arq >> pag;
            arq >> tipo;

            if(tipo == 'P')
            {
                if(!verificaInicializacaoF(&P))
                {
                    cout << "\nERRO: inicializar fila P";
                    continue;
                }
                else if(cheiaF(&P))
                {
                    cout << "\nFILA CHEIA";
                    continue;
                }
                else
                {
                    enfileiraF(&P, Documentos(nome,pag));
                    cout << "\nO documento " << nome << " (" << pag << " pag)  foi adicionado na fila P";
                }

            }

            if(tipo == 'N')
            {
                if(!verificaInicializacaoF(&N))
                {
                    cout << "\nERRO: inicializar fila P";
                    continue;
                }
                else if(cheiaF(&N))
                {
                    cout << "\nFILA CHEIA";
                    continue;
                }
                else
                {
                    enfileiraF(&N, Documentos(nome,pag));
                    cout << "\nO documento " << nome << " (" << pag << " pag)  foi adicionado na fila N";
                }

            }

        }

        else if(operacao == "IMPRIMIRDOC")
        {
            if(!verificaInicializacaoF(&P) && !verificaInicializacaoF(&N))
            {
                cout << "\nERRO: inicializar filas P e N";
                continue;
            }

            if(!vaziaF(&P))
            {
               x = desenfileiraF(&P);
               cout << "\nO documento " << x.nome << " foi impresso.";

            }
            else if(!vaziaF(&N))
            {
               x =  desenfileiraF(&N);
               cout << "\nO documento " << x.nome << " foi impresso.";
            }


            if(vaziaF(&P) && vaziaF(&N))
            {
                cout << "\nN�o h� documentos para imprimir";
                continue;
            }


        }
        else if(operacao == "CONSULTAR") ///FEITA
        {
            arq >> nome;
            arq >> tipo;

            bool res;

            if(tipo == 'P')
            {
                if (!verificaInicializacaoF(&P))
                {
                    cout << "\nERRO: inicializar fila P";
                    continue;

                }
                else if(vaziaF(&P))
                {
                    cout << "\nFila vazia";
                    continue;
                }

                if(consultaF(&P, nome))
                {
                    cout << "\nO documento "<< nome<< " encontra-se na fila P";
                }
                else
                {
                    cout << "\nO documento "<< nome<< " n�o est� na fila P";
                }


            }

            if(tipo == 'N')
            {
                if (!verificaInicializacaoF(&N))
                {
                    cout << "\nERRO: inicializar fila P";
                    continue;

                }
                else if(vaziaF(&N))
                {
                    cout << "\nFila vazia";
                    continue;
                }

                if(consultaF(&N, nome))
                {
                    cout << "\nO documento "<< nome<< " encontra-se na fila P";
                }
                else
                {
                    cout << "\nO documento "<< nome<< " n�o est� na fila N";
                }


            }

        }

       else if(operacao == "MOSTRAR") ///FEITA
        {
            arq >> tipo;

            if(tipo == 'P')
            {
                if (!verificaInicializacaoF(&P))
                {
                    cout << "\nERRO: inicializar fila P";

                }
                else if(!vaziaF(&P))
                {
                    mostraF(&P);
                }
                else
                {
                    cout << "\nFila Vazia";
                }
            }

            if(tipo == 'N')
            {
                if (!verificaInicializacaoF(&N))
                {
                    cout << "\nERRO: inicializar fila N";

                }
                else if(!vaziaF(&N))
                {
                    mostraF(&N);
                }
                else
                {
                    cout << "\nFila Vazia";
                }
            }

        }

        else if(operacao == "INICIALIZAR") ///FEITA
        {
            arq >> tam;

            destroiF(&P);
            destroiF(&N);

            inicializaF(&P,tam);
            inicializaF(&N,tam);

            cout << "\nAs fila P e N foram inicializadas com o tamanho " << tam;

        }

        else if(operacao == "TOTALPAG") ///FEITA
        {
            int somaP = 0;
            int somaN = 0;

            somaP = contapaginasF(&P,somaP);
            somaN = contapaginasF(&N,somaN);

            somaP += somaN;

            cout << "\n"<< somaP << " p�gina (s)";
        }



    usleep(1000000);

    }

    cout << "\n\n\n";

}
