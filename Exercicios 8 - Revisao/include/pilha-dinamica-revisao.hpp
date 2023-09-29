#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha


struct NoPilha
{
    Ficha dado; //informa��o do n�
    NoPilha *prox; //pr�ximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha()  //Construtor. Inicializa��o da pilha
    {
        topo = nullptr;
    }
};


bool vaziaP(Pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}


//push
bool empilhaP(Pilha *p, Ficha dado)
{
    NoPilha *novo =  new NoPilha(); //cria um novo n�
    if (novo == NULL) /// sistema n�o conseguiu alocar a mem�ria
        return false;

    novo->dado = dado ; //armazena a informa��o no n�
    novo->prox = p->topo; //o pr�ximo elemento do n� criado ser� o �ltimo elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o n� criado.
    return true;
}

//pop
Ficha desempilhaP(Pilha *p)
{
    Ficha dado;

    // se n�o estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado; //pega o dado armazenado no n� do topo
        NoPilha *apagar = p->topo; //guarda o n� do topo em uma vari�vel auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o pr�ximo elemento;

        delete apagar;  /// libera a mem�ria
    }

    return dado;
}

//peek
Ficha espiaP(Pilha* p)
{
    Ficha dado;

    if (vaziaP(p) == false)
        dado = p->topo->dado;

    return dado;
}


void mostraP(Pilha *p)
{
    cout << "\nPILHA: {";

    if(vaziaP(p) == false)
    {

        NoPilha *no = p->topo;
        while (no != NULL)
        {
            cout << "[ " << no->dado.nome << ", c= "<< no->dado.codigo << ", i= " << no->dado.idade << ", s= " << no->dado.saldo << " ]";

            no = no->prox;
            if(no != NULL)
            {
                cout << ", \n";
            }
        }
    }
    cout << "} ";
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor n�o existe na pilha
bool buscaViaCodigoP(Pilha *p, int codigo)
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == codigo)
            return true;

        no = no->prox;
    }

    return false;

}

void destroiP(Pilha *p)
{
    Ficha dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}

Ficha retiraDados(Pilha *p, int codigo)
{
    Ficha dado;

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == codigo)
        {
            dado = no->dado;
            return dado;
        }
        else
        {
            no = no->prox;
        }

    }

}

float somaSaldo(Pilha *p)
{
    float soma = 0;

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        soma += no->dado.saldo;

        no = no->prox;
    }

    return soma;
}

void sacaViaCodigoP(Pilha *p, int codigo, int valor)
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == codigo)
        {
            no->dado.saldo -= valor;
            return;
        }
        else
        {
            no = no->prox;
        }
    }

}

void depositoViaCodigoP(Pilha *p, int codigo, int valor)
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == codigo)
        {
            no->dado.saldo += valor;
            return;
        }
        else
        {
            no = no->prox;
        }
    }

}

int contaNegativados(Pilha *p)
{
   int cont = 0;

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.saldo < 0)
        {
              cont++;
        }

        no = no->prox;
    }

    return cont;
}

int contaCadastrados(Pilha *p)
{
   int cont = 0;

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }

    return cont;
}
#endif // _HPP_PILHA_DINAMICA




