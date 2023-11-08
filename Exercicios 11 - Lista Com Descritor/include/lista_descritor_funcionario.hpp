#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

#include <cstring>
#include <string>
#include <iostream>



struct Funcionario
{
    int codigo;
    std::string nome;
    int idade;
    float salario;
    Funcionario() // construtor
    {
        codigo = 0;
        nome="";
        idade = 0;
        salario = 0.0f;
    }

    Funcionario(int cod, std::string nam, int ida, float sal) // construtor
    {
        codigo = cod;
        nome= nam;
        idade = ida;
        salario = sal;
    }

    //operadores usados na busca e remoção de nós
    bool operator!=(const Funcionario& f)
    {
        if(codigo != f.codigo)
            return true;
        if(nome != f.nome)
            return true;
        if(idade != f.idade)
            return true;
        if(salario != f.salario)
            return true;

        return false;
    }

    bool operator==(const Funcionario& f)
    {
        if(codigo != f.codigo)
            return false;
        if(nome != f.nome)
            return false;
        if(idade != f.idade)
            return false;
        if(salario != f.salario)
            return false;

        return true;
    }

    //operador usado na ordenação
    bool operator > (const Funcionario& f)
    {
        if(strcmpi(nome.c_str(), f.nome.c_str()) > 0 )
            return true;
        else
            return false;
    }

    /*
     bool operator < (const Funcionario& f)
    {
        if(nome < f.nome )
            return true;
        else
            return false;
    }
    */
};

struct No
{
    Funcionario dado;
    struct No *prox;
    No() // construtor
    {
        prox = nullptr;
    }
};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
};


/// quando cout receber uma struct No
std::ostream& operator<<(std::ostream& os, const Funcionario &f)
{
    /// cout << n
    return os << "[" << f.codigo << ", " << f.nome << ", " <<  f.idade << ", " <<  f.salario << "]";
}

/// quando cout receber uma struct No
ostream& operator<<(ostream& os, const No *n)
{
    /// cout << n
    return os << n->dado;
}



/// quanto cout receber uma struct Lista
ostream& operator << (ostream& os, Lista &l)
{
    No *n = l.inicio;
    os << "L:{";
    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }
    os << "}";
    return os;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;

    cout << "L:{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

void destroiL(Lista *lista)
{
    No *n = lista->inicio;
    while(n != nullptr)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}


bool vaziaL(Lista *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

///insere no início da lista
bool insereInicioL(Lista *lista, Funcionario valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}
bool insereFimL(Lista *lista, Funcionario valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = NULL;

    if(vaziaL(lista))
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
    return true;
}


bool removeL(Lista *lista, Funcionario valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endereço do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual é NULL >> não encontrou
        return false;
    if (!anterior) /// se anterior é igual a NULL
    {
        /// o elemento a ser excluído está no início da lista
        lista->inicio = atual->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox)/// se for retirado último da lista
            lista->fim = anterior;
    }
    /// libera a memória do elemento
    lista->tamanho--;

    delete(atual);
    return true;

}

No* buscaL(Lista *lista, Funcionario valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

///• Função para ler um funcionário no início da lista;
Funcionario lerInicioL(Lista *lista)
{
    Funcionario n;
    if(lista->inicio == NULL)
    {
        return n ;
    }
    n = lista->inicio->dado;

    return n;
}

///• Função para ler um funcionário no final da lista:
Funcionario lerFimL(Lista *lista)
{
    Funcionario f;

    if(lista->inicio == NULL)
    {
        cout << "\nLista Vazia!";
        return f;
    }
    f = lista->fim->dado;
    return f;
}


///• Função para remover um funcionário do início da lista;
Funcionario removeInicio(Lista *lista)
{
    Funcionario n;
    No *aux;

    if(lista->inicio == NULL)
    {
        cout << "\nLista Vazia";
        return n;

    }
    if(lista->tamanho == 1)
    {
        n = lista->inicio->dado;
        lista->tamanho--;
        delete lista->inicio;
        lista->inicio = NULL;
        lista->fim = NULL;
        return n;
    }

    n = lista->inicio->dado;
    lista->tamanho--;
    aux = lista->inicio;
    lista->inicio = lista->inicio->prox;

    delete aux;
    return n;

}


///FUNCAO PARA CALCULAR A MEDIA SALARIAL
float mediaSalarial(Lista *lista)
{
    float media = 0;
    No *atual = lista->inicio;

    if(lista->inicio == NULL)
    {
        cout << "\nLista Vazia";
        return media;
    }

    while(atual != NULL)
    {
        media += atual->dado.salario;
        atual = atual->prox;
    }
    return media;

}


///• Função para imprimir o nome de todos os funcionários que possuem salário menor que a média.
void imprimeMenorMedia(Lista *lista, float media)
{
    No *atual = lista->inicio;

    if(lista->inicio == NULL)
    {
        cout << "\nLista Vazia";
        return;
    }

    while(atual != NULL)
    {
        if(atual->dado.salario < media)
        {
            cout << atual->dado.nome << " ";
        }
        atual = atual->prox;
    }

}



///• Função para ordenar a lista de funcionários em ordem alfabética:
void ordenaL(Lista *lista)
{
    No *atual = lista->inicio;
    Funcionario aux;
    int trocas;


    if(lista->inicio == NULL)
    {
        cout << "\nLista Vazia";
        return;
    }

    do
    {
        trocas = 0;
        while(atual->prox != NULL)
        {
            if(atual->dado.nome > atual->prox->dado.nome)
            {
                aux = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = aux;
                trocas++;
            }
            atual = atual->prox;
        }
        atual = lista->inicio;
    }
    while (trocas != 0);
        return;
}





#endif // _HPP_LISTA_DESCRITOR



