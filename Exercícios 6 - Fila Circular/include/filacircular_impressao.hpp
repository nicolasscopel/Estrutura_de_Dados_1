
#ifndef _HPP_FILA
#define _HPP_FILA

#include <iomanip> //biblioteca usada para formatar a impress�o da fila

struct Fila
{
    int tam; //tamanho do vetor de dados
    int total; //total de elementos armazenados na fila
    int inicio; //ponteiro para o elemento armazenado no inicio da fila
    int fim; //ponteiro para o fim da fila (posi��o do vetor onde ser� armazenado o pr�ximo elemento)
    Documentos *dados;//ponteiro para o vetor que ser� alocado para armazenar os dados

    Fila() //Construtor. Usado para inicializar os dados das vari�veis da struct
    {
        tam =0;
        total = 0;
        inicio = 0;
        fim = 0;
        dados = nullptr;
    }
};



void inicializaF(Fila *f, int tam) /// inicializa��o da fila
{
    f->tam = tam;
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->dados = new Documentos[tam];/// aloca mem�ria para vetor
}

bool verificaInicializacaoF(Fila *f) //verifica de a fila foi inicializada
{
    if(f->dados != NULL)
        return true;
    else
        return false;
}

void destroiF(Fila *f)
{
    f->fim = 0;
    f->inicio = 0;
    f->total = 0;
    f->tam = 0;

    if(verificaInicializacaoF(f) == true)
    {
        delete[] (f->dados);
        f->dados = nullptr;
    }
}


bool vaziaF(Fila *f)// fila vazia
{
    if (f->total == 0)
        return true;
    else
        return false;
}

bool cheiaF(Fila *f)// fila cheia
{
    if (f->total == f->tam)
        return true;
    else
        return false;
}

//Enqueue
bool enfileiraF(Fila *f, Documentos valor) /// incluir valor na fila
{
    if (verificaInicializacaoF(f)==false || cheiaF(f) == true) // retorna false se a fila n�o foi inicializada ou se cheia
        return false;

    //inserir no final da fila
    f->dados[f->fim] = valor;

    //incrementa a quantidade de elementos armazenados na fila
    f->total++;

    //avan�a o ponteiro fim
    f->fim++;

    if(f->fim>=f->tam)
       f->fim = 0; //circular

    return true;
}

//Dequeue
Documentos desenfileiraF(Fila *f)  //retirar da fila
{
    Documentos valor;

    if (vaziaF(f) == true) // retorna 0 se fila vazia
        return valor;

    //remover do inicio da fila
    valor = f->dados[f->inicio];

    //diminui a quantidade de elementos armazenados na fila
    f->total--;

    //avan�a o ponteiro in�cio
    f->inicio++;

    if(f->inicio>=f->tam)
       f->inicio = 0; //circular

    return valor;
}

//Peek
Documentos espiaF(Fila *f) ///peek
{
    Documentos valor;

    if(vaziaF(f)==true)// retorna 0 se fila vazia
        return valor;

    valor = f->dados[f->inicio];
    return valor;
}

void mostraF(Fila *f)
{
    cout << "\n";
    if (vaziaF(f) == false)
    {
        int idx = f->inicio;

        for(int i = 0; i < f->total; i++)
        {
            cout << f->dados[idx].nome ; //imprime o dado armazenado na fila

            if(i < f->total-1)
                cout << ", ";


            idx++;
            if(idx >= f->tam)
                idx=0; //circular
        }

    }else
        cout << "Fila vazia!\n";
}

bool consultaF(Fila *f, string nome)
{
    int idx = f->inicio;

    for(int i = 0; i < f->total; i++)
    {
        if(f->dados[idx].nome == nome)
        {
            return true;

        }
        if(idx >= f->tam)
                idx=0; //circular
    }
    return false;

}

int contapaginasF(Fila *f, int soma)
{
    int idx = f->inicio;
    for(int i = 0; i < f->total; i++)
    {
        soma += f->dados[idx].paginas;

        if(idx >= f->tam)
                idx=0; //circular
    }

    return soma;

}




#endif // _HPP_FILA

