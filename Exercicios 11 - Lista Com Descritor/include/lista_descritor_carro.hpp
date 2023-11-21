#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

#include <cstring>
#include <string>
#include <iostream>



struct Carro
{

    std::string placa;
    int ano;
    std::string fabricante;
    std::string modelo;
    Carro() // construtor
    {
        placa = "";
        ano = 0;
        fabricante="";
        modelo="";
    }

    Carro( std::string p, int a, std::string f, std::string m) // construtor
    {
        placa = p;
        ano = a;
        fabricante = f ;
        modelo = m;
    }

    //operadores usados na busca e remo��o de n�s
    bool operator!=(const Carro& c)
    {
        if(placa != c.placa)
            return true;
        if(ano != c.ano)
            return true;
        if(fabricante != c.fabricante)
            return true;
        if(modelo != c.modelo)
            return true;

        return false;
    }

    bool operator==(const Carro& c)
    {
        if(placa != c.placa)
            return false;
       if(ano != c.ano)
            return false;
       if(fabricante != c.fabricante)
            return false;
        if(modelo != c.modelo)
            return false;

        return true;
    }

    //operador usado na ordena��o
    bool operator > (const Carro& c)
    {
        if(strcmpi(placa.c_str(), c.placa.c_str()) > 0 )
            return true;
        else
            return false;
    }

    /*
     bool operator < (const Carro& f)
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
    Carro dado;
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
std::ostream& operator<<(std::ostream& os, const Carro &c)
{
    /// cout << n
    return os << "[" << c.placa << ", " << c.ano << ", " <<  c.fabricante << ", " <<  c.modelo << "]";
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
    while(n != NULL ) /// enquanto n n�o for NULL fica no la�o
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

///insere no in�cio da lista
bool insereInicioL(Lista *lista, Carro valor)
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
bool insereFimL(Lista *lista, Carro valor)
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


bool removeL(Lista *lista, string valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no la�o enquanto tiver elementos na lista
    /// e n�o encontrar o valor procurado
    while(atual && atual->dado.placa != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do la�o sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endere�o do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual � NULL >> n�o encontrou
        return false;
    if (!anterior) /// se anterior � igual a NULL
    {
        /// o elemento a ser exclu�do est� no in�cio da lista
        lista->inicio = atual->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox)/// se for retirado �ltimo da lista
            lista->fim = anterior;
    }
    /// libera a mem�ria do elemento
    lista->tamanho--;

    delete(atual);
    return true;

}


bool removeFabricanteL(Lista *lista, string valor)
{
    No *n = lista->inicio;
   while(n)
   {
        if(n->dado.fabricante == valor && n->dado.ano > 2000)
        {
            removeL(lista,n->dado.placa);
        }

        n = n->prox;
   }
   return true;

}

void consultaPlacaL(Lista *lista, string valor)
{
    No *n = lista->inicio;
   while(n)
   {
        if(n->dado.fabricante == valor)
        {
            cout << n->dado.placa << " - ";
        }

        n = n->prox;
   }
   return;

}

No* buscaL(Lista *lista, Carro valor)
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

///� Fun��o para ler um funcion�rio no in�cio da lista;
Carro lerInicioL(Lista *lista)
{
    Carro n;
    if(lista->inicio == NULL)
    {
        return n ;
    }
    n = lista->inicio->dado;

    return n;
}

///� Fun��o para ler um funcion�rio no final da lista:
Carro lerFimL(Lista *lista)
{
    Carro f;

    if(lista->inicio == NULL)
    {
        cout << "\nLista Vazia!";
        return f;
    }
    f = lista->fim->dado;
    return f;
}


///� Fun��o para remover um funcion�rio do in�cio da lista;
Carro removeInicio(Lista *lista)
{
    Carro n;
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





///� Fun��o para ordenar a lista de funcion�rios em ordem alfab�tica:
void ordenaModeloL(Lista *lista)
{
    No *atual = lista->inicio;
    Carro aux;
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
            if(atual->dado.modelo > atual->prox->dado.modelo)
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

void ordenaAnoL(Lista *lista)
{
    No *atual = lista->inicio;
    Carro aux;
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
            if(atual->dado.ano > atual->prox->dado.ano)
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

void inverteL(Lista *lista, Lista *aux)
{

     if(lista->inicio == NULL)
    {
        cout << "\nLista Vazia";
        return;
    }

    Carro n;

    while(lista->inicio != NULL)
    {
        n = removeInicio(lista);
        insereInicioL(aux,n);

    }

     while(aux->inicio != NULL)
    {
        n = removeInicio(aux);
        insereFimL(lista,n);

    }

    return;


}

Lista copiaL(Lista *l1, Lista *l2)
{
    No *n = l1->inicio;

    while(n!=NULL)
    {
        insereFimL(l2, n->dado);
        n = n->prox;
    }

}






#endif // _HPP_LISTA_DESCRITOR



