#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> //biblioteca usada para formatar a impressão da pilha


struct NoPilha
{
    Ficha dado; //informação do nó
    NoPilha *prox; //próximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha()  //Construtor. Inicialização da pilha
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
    NoPilha *novo =  new NoPilha(); //cria um novo nó
    if (novo == NULL) /// sistema não conseguiu alocar a memória
        return false;

    novo->dado = dado ; //armazena a informação no nó
    novo->prox = p->topo; //o próximo elemento do nó criado será o último elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o nó criado.
    return true;
}

//pop
Ficha desempilhaP(Pilha *p)
{
    Ficha dado;

    // se não estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado; //pega o dado armazenado no nó do topo
        NoPilha *apagar = p->topo; //guarda o nó do topo em uma variável auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o próximo elemento;

        delete apagar;  /// libera a memória
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
/// retorna false se o valor não existe na pilha
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




