#include<iostream>
#include<string>
#include<ctime>

using namespace std;


int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    //MATRIZ  3X4, vai posuir 3 linha de 4 colunas!
    const int L = 3, C=4;


    //arrays para armazenando os valores das linhas da matriz:
    int *l0 = new int[C];
    int *l1 = new int[C];
    int *l2 = new int[C];

    for (int j=0; j<C ; j++)
    {
        l0[j] = rand()%100;
        l1[j] = rand()%100;
        l2[j] = rand()%100;
    }


    //imprimindo a "matriz", ou seja, os dados armazenados nos arrays
    for (int i=0; i<L ; i++)
    {
        for (int j=0; j<C ; j++)
        {
            if(i==0)
                cout << l0[j] << "\t";
            else if(i==1)
                cout << l1[j] << "\t";
            else if(i==2)
                cout << l2[j] << "\t";
        }
        cout << endl;
    }

    //O que s�o l0, l1, l2?
    //- S�o ponteiros do tipo inteiro!
    //- Armazenam o endere�o de mem�ria para o PRIMEIRO valor do vetor
    //- l0 � o ponteiro para o primeiro valor da linha 0
    //- l1 � o ponteiro para o primeiro valor da linha 1
    //- l2 � o ponteiro para o primeiro valor da linha 2

    cout << "Endere�o de l0 (l0): " << l0 << endl;
    cout << "Endere�o de l0 (l0): " << (++l0) << endl;
    cout << "Endere�o de l1 (l1): " << l1 << endl;
    cout << "Endere�o de l2 (l2): " << l2 << endl;

    cout << "Valor de l0 (*l0): " << *l0 << endl;
    cout << "Valor de l1 (*l1): " << *l1 << endl;
    cout << "Valor de l2 (*l2): " << *l2 << endl;


    //O que s�o l0, l1, l2: S�o ponteiros do tipo inteiro!
    //Podemos criar um array para armazenar qualquer tipo de dados, inclusive um arrray para armazenar ponteiros do tipo int
    int **matriz = new int*[L]; //note que "new int*", pois vou guardar ponteiros do tipo int

    //guardando o endere�os de mem�ria de cada vetor
    matriz[0] = l0;
    matriz[1] = l1;
    matriz[2] = l2;

     //imprimindo a "matriz", ou seja, os dados armazenados nos arrays
    for (int i=0; i<L ; i++)
    {
        for (int j=0; j<C ; j++)
        {
            //note que:
            //- para imprimir um dado de um array, usamos l0[j], l1[j] ou l2[j]
            //- sabendo que (matriz[0] = l0), (matriz[1] = l1), temos:
             cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    //liberar mem�ria
    for (int i=0; i<L ; i++)
        delete[] matriz[i]; //remover cada array que cont�m os valores da matriz

    delete[] matriz; //remover o array que armazena os ponteiros de cada vetor




    return 0;
}
