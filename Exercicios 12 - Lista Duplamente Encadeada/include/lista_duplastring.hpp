#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA


struct No
{
    string dado;
    No *prox;
    No *ant;
    No() // construtor
    {
        prox = nullptr;
        ant = nullptr;
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
ostream& operator << (ostream& os, const Lista &l)
{
    No *n = l.inicio;
    os << "L[" << l.tamanho << "]:{";
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

void destroiL(Lista *l)
{
    No *n = l->inicio;
    while(n)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = NULL;
    l->inicio = NULL;
    l->tamanho = 0;
}

bool vaziaL(Lista *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n;
        n = n->prox;
        if(n)
            cout << ", ";
    }
    cout << "}\n";
}

void mostrarInversoL(Lista *lista)
{
    No *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n;
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}


///insere no início da lista
bool insereInicioL(Lista *lista, string valor)
{

    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->ant = nullptr; //Se o novo nó será adicionado no início da lista, o ponteiro *ant do primeiro nó sempre é nulo
    novo->prox = lista->inicio;

    if (!lista->fim) //lista vazia?
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

    return true;
}

///insere no final da lista
bool insereFinalL(Lista *lista, string valor)
{

    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = nullptr; //Se o novo nó será adicionado no final da lista, o ponteiro *prox do ultimo nó sempre é nulo
    novo->ant = lista->fim;

    if (!lista->inicio) //lista vazia?
        lista->inicio = novo;
    else
        lista->fim->prox = novo;

    lista->fim = novo;
    lista->tamanho++;

    return true;
}

No* buscaL(Lista *lista, string valor)
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

string removeInicioL(Lista *lista)
{

    No *no = new No();
    string valor = "";

    if(lista->inicio == nullptr)
    {
        return 0;
    }

    valor = lista->inicio->dado;
    if(lista->inicio->prox == nullptr) ///LISTA SO TEM UM ELEMENTO
    {

        no = lista->inicio;
        lista->fim = nullptr;
        lista->inicio = nullptr;
        lista->tamanho = 0;

        delete(no);
        return valor;

    }

    no = lista->inicio;
    No *segundo = lista->inicio->prox;

    ///LISTA COM MAIS DE UM ELEMENTO
    lista->inicio = segundo;
    segundo->ant = nullptr;
    lista->tamanho --;

    delete(no);
    return valor;

}

string removeFinalL(Lista *lista)
{

    No *no = new No();
    string valor = "";

    if(lista->inicio == nullptr)
    {
        return 0;
    }


    valor = lista->fim->dado;

    if(lista->fim->ant == nullptr) ///LISTA SO TEM UM ELEMENTO
    {
        no = lista->fim;
        lista->fim = nullptr;
        lista->inicio = nullptr;
        lista->tamanho = 0;

        delete(no);
        return valor;

    }

    No *antes = lista->fim->ant;
    no = lista->fim;

    ///LISTA COM MAIS DE UM ELEMENTO
    lista->fim = antes;
    antes->prox = nullptr;
    lista->tamanho --;

    delete(no);
    return valor;

}

bool removerNoL(Lista *lista, No *no)
{
    if(!no || !lista || vaziaL(lista))
        return false;

    if (!no->ant) /// se anterior é igual a NULL, o elemento a ser excluído está no início da lista
    {
        lista->inicio = no->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;

    }else{ /// elemento está no meio ou no fim

        no->ant->prox = no->prox;
        if (!no->prox)/// se for retirado último da lista
            lista->fim = no->ant;
        else
            no->prox->ant = no->ant;

    }

    /// libera a memória do elemento
    lista->tamanho--;
    delete(no);
    return true;
}

bool removeL(Lista *lista, string valor)
{
    No* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}


///remove da lista todas as ocorrências do parâmetro valor
void removeTodos(Lista *lista, string valor)
{
    No *atual = lista->inicio;

    if(lista->inicio == nullptr) /// LISTA VAZIA
    {
        return;
    }

    while(atual)
    {
        if(atual->dado == valor)
        {
            removerNoL(lista,atual);

        }
        atual = atual->prox;
    }
    return;
}

void ordenaL(Lista *lista)
{
    No *atual = lista->inicio;
    No *aux = new No();
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
            if(atual->dado < atual->prox->dado)
            {
                aux->dado = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = aux->dado;
                trocas++;
            }
            atual = atual->prox;
        }
        atual = lista->inicio;
    }
    while (trocas != 0);
        return;
}

Lista copiaL(Lista *l1, Lista *l2)
{
    No *n = l1->inicio;

    while(n!=NULL)
    {
        insereFinalL(l2, n->dado);
        n = n->prox;
    }

}


///Retorna uma nova lista, ordenada, com os X maiores elementos de lista
///Se X for maior que o tamanho de lista, a lista retornada deve conter todos os
///elementos de L de forma ordenada.
Lista leMaiores(Lista *lista, int x)
{

    Lista ret = Lista();
    Lista copia = Lista();
    No *aux = new No();
    int cont = 0;

    if(x >= lista->tamanho)
    {
        copiaL(lista,&ret);
        ordenaL(&ret);
        return ret;
    }

    copiaL(lista,&copia);
    ordenaL(&copia);

   aux = copia.inicio;  ///UTILIZA O PONTO POIS FOI CRIADO DENTRO DA FUNÇÃO (COPIA)


    while(cont < x)
    {
        insereFinalL(&ret,aux->dado);
        aux = aux->prox;
        cont++;
    }
    return ret;



}

void mostraCaminhoVoltaL(Lista *lista)
{
    string valor;
    cout << "\nVOLTA: ";

    Lista volta = Lista();

    No *no = lista->inicio;

    while(no)
    {
        valor = no->dado;

        if(valor == "esquerda")
        {
            insereInicioL(&volta,"direita");
        }
        if(valor == "direita")
        {
             insereInicioL(&volta,"esquerda");
        }
        if(valor == "cima")
        {
             insereInicioL(&volta,"baixo");
        }
        if(valor == "baixo")
        {
             insereInicioL(&volta,"cima");
        }

        no = no->prox;
    }

    mostraL(&volta);


    destroiL(&volta);

}


#endif // _HPP_LISTA_DUPLA



