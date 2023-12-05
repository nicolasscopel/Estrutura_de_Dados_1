#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR



struct No
{
    int dado;
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


    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }

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
bool insereInicioL(Lista *lista, int valor)
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
bool insereFimL(Lista *lista, int valor)
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



bool removeL(Lista *lista, int valor)
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

No* buscaL(Lista *lista, int valor)
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

bool buscaElementoL(Lista *lista, int valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return true;

        n = n->prox;
    }

    return false;
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



void mostraLCrescente(Lista *lista)
{

    Lista copia = Lista();
    copiaL(lista,&copia);

    No *atual = copia.inicio;

    int aux;
    int trocas;

    do
    {
        trocas = 0;
        while(atual->prox != NULL)
        {
            if(atual->dado > atual->prox->dado)
            {
                aux = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = aux;
                trocas++;
            }
            atual = atual->prox;
        }
        atual = copia.inicio;
    }
    while (trocas != 0);

    mostraL(&copia);

    destroiL(&copia);


}

void mostraLDecrescente(Lista *lista)
{

    Lista copia = Lista();
    copiaL(lista,&copia);

   No *atual = copia.inicio;

    int aux;
    int trocas;

    do
    {
        trocas = 0;
        while(atual->prox != NULL)
        {
            if(atual->dado < atual->prox->dado)
            {
                aux = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = aux;
                trocas++;
            }
            atual = atual->prox;
        }
        atual = copia.inicio;
    }
    while (trocas != 0);

    mostraL(&copia);

    destroiL(&copia);


}

void mostraDifL(Lista *princ ,Lista *subt)
{
    No *atual = princ->inicio;
    No *sub = subt->inicio;
    int v = 0;

    Lista saida = Lista();

    while(atual)
    {
        v = 0;
        while(sub)
        {
            if(atual->dado == sub->dado)
            {
                v++;
            }

            sub = sub->prox;
        }
        if(v == 0)
        {
            insereFimL(&saida,atual->dado);
        }
        sub = subt->inicio;
        atual = atual->prox;
    }

    mostraLCrescente(&saida);
    destroiL(&saida);


}


void removeTodos(Lista *lista)
{
    destroiL(lista);
}

void ordenaL(Lista *lista)
{
    No *atual = lista->inicio;
    int aux;
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
            if(atual->dado > atual->prox->dado)
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

float verificaMedianaL(Lista *lista)
{
    float ret;
    int cont = 0,pos;
    Lista copia = Lista();
    copiaL(lista,&copia);

    ordenaL(&copia);

     No *atual = new No();

    if(lista->tamanho == 1)
    {
        atual = lista->inicio;
        ret = atual->dado;
        return ret;
    }
    if(lista->tamanho == 2)
    {
        atual = lista->inicio;
        ret = atual->dado;
        ret += atual->prox->dado;

        return ret/2.00;
    }

    if(lista->tamanho % 2 == 1)
    {
        pos = lista->tamanho / 2;
        atual = copia.inicio;

        while(pos != cont)
        {
            cont++;
            atual = atual->prox;

        }
        ret = atual->dado;

    }

    if(lista->tamanho % 2 == 0)
    {
        atual = copia.inicio;
        pos = lista->tamanho / 2;
        pos--;

        while(pos != cont)
        {
            cont++;
            atual = atual->prox;

        }
        ret = atual->dado;
        ret += atual->prox->dado;
        ret = ret/2.00;
    }


    return ret;
}

void verificaModaL(Lista *lista)
{
    Lista aparece = Lista();
    Lista moda = Lista();
    int cont,chave, maximo = 0;
    No *atual = lista->inicio;
    No *controle = lista->inicio;

    while(controle)
    {
        chave = controle->dado;
        int cont = 0;

        while(atual)
        {
            if(atual->dado == chave)
            {
                cont++;
            }

            atual = atual->prox;
        }
        if(cont > maximo)
        {
            maximo = cont;
        }
        insereFimL(&aparece,cont);

        atual = lista->inicio;

        controle = controle->prox;
    }

    atual = lista->inicio;
    controle = aparece.inicio;


    while(atual)
    {
        if(controle->dado == maximo)
        {
            if(buscaElementoL(&moda,atual->dado) == false)
            {
                insereFimL(&moda,atual->dado);
            }
        }

        atual = atual->prox;
        controle = controle->prox;
    }


    if(maximo == 1)
    {
        cout << "VAZIA!";
    }
    else{
        mostraL(&moda);
    }

    destroiL(&moda);
    destroiL(&aparece);


    return;


}


#endif // _HPP_LISTA_DESCRITOR



