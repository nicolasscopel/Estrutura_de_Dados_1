#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA



struct No
{
    char dado;
    struct No *prox;
};


void inicializaL(No **lista)
{
    *lista = NULL;
}

bool vaziaL(No **lista)
{
    if( (*lista) == NULL )
        return true;
    else
        return false;
}

/// excluir todos os elementos da lista
void destroiL(No **lista)
{
    No *n = *lista;
    while (n != NULL)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

void mostraL(No **lista)
{
    No *n = *lista;

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

///insere no in�cio da lista
bool insereInicioL(No **lista, char valor)
{

    No *novo = new No(); // aloca mem�ria para o n�
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

///Insere um valor no final da lista
void insereFinalL(No **lista, char valor)
{
    No *N = *lista;
    No *novo = new No();

    novo->dado = valor;
    novo->prox = NULL;

    if(vaziaL(lista) == true)
    {
        *lista = novo;
        return;
    }

    while(N->prox != NULL)
    {
        N = N->prox;
    }

    N->prox = novo;
}

///retorna o valor do primeiro elemento da lista SEM remov�-lo
char leInicioL(No **lista)
{
    char dado = ' ';

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado

    return dado;
}

///retorna o valor do ULTIMO elemento da lista SEM remov�-lo
char leFinalL(No **lista)
{
    char dado = ' ';

    No *N = *lista;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado

    while(N->prox != NULL)
    {
        N = N->prox;
    }

    dado = N->dado;

    return dado;
}

///retorna o valor do primeiro elemento da lista e REMOVE o elemento
char removeInicioL(No **lista)
{
    No* aux;
   char dado = ' ';

    if(vaziaL(lista) == false)
    {
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado
        aux = *lista; //pega a referenccia do primeiro n�, o qual ser� removido

        *lista = (*lista)->prox; //atualiza o in�cio da lista para o pr�ximo elemento

        delete aux;
    }

    return dado;
}

///retorna o valor do ultimo elemento da lista e REMOVE o elemento
char removeFinalL(No **lista)
{
    No *anterior = NULL;
    No *fim = *lista;
    char dado = ' ';

    if(vaziaL(lista) == false)
    {
        if(fim->prox == NULL)
        {
            dado = fim->dado;

            *lista = NULL;

            return dado;
        }

        while(fim->prox != NULL)
        {
            anterior = fim;
            fim = fim->prox;
        }

        dado = fim->dado;

        anterior->prox = NULL;

        delete(fim);
    }


    return dado;
}



///remover um n� da lista com um valor espec�fico
bool removeL(No **lista, char valor)
{
    No *anterior = NULL;
    No *atual = *lista;
    ///fica no la�o enquanto tiver elementos na lista
    /// e n�o encontrar o valor procurado
    while(atual!=NULL && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do la�o sem encontrar o valor (atual==NULL)
    /// se encontrar -> atual tem o endere�o do elemento para excluir
    if(atual == NULL) /// se atual � NULL -> n�o encontrou
        return false;

    if (anterior == NULL)
    {
        /// o elemento a ser exclu�do est� no in�cio da lista
        *lista = atual->prox;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = atual->prox;
    }

    /// libera a mem�ria do elemento
    delete(atual);
    return true;
}


No* buscaL(No **lista, char valor)
{
    No *n = *lista;
    while (n != NULL)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return NULL;
}

int totalL(No **lista)
{
    int cont = 0;

    if(vaziaL(lista))
    {
        return 0;
    }

    No *n = *lista;

    while(n != NULL ) /// enquanto n n�o for NULL fica no la�o
    {
        n = n->prox;
        cont++;
    }

    return cont;
}

///verifica se duas listas s�o iguais
bool igualL(No **lista1, No **lista2)
{

    No *N1 = *lista1;
    No *N2 = *lista2;



    while(N1 && N2)
    {

        if(N1->dado != N2->dado)
        {
            return false;
        }

        N1 = N1->prox;
        N2 = N2->prox;
    }

    if(!N1 && !N2)
    {
        return true;
    }
    else
    {
        return false;
    }

}

///retorna o valor do dado armazenado em um n� da lista, com base na posi��o passada por par�metro
///se posi��o=0, a fun��o deve retornar o valor do primeiro n� da lista
///se posi��o=1, a fun��o deve retornar o valor do segundo n� da lista

char lePosicao(No **lista, int posicao)
{
    int cont = 0;

    No *n = *lista;

    while(cont != posicao)
    {
        n = n->prox;
        cont++;
    }
    char valor = n->dado;

     return valor;

}

///Uni�o de duas listas
void uniao(No **lista1, No **lista2, No **listaSaida)
{
    No *l1 = *lista1;
    No *l2 = *lista2;

    char valor;

    while(l1 != NULL)
    {
        valor = l1->dado;
        insereInicioL(&(*listaSaida),valor);
        l1 = l1->prox;
    }
    while(l2 != NULL)
    {
        valor = l2->dado;
        insereInicioL(&(*listaSaida),valor);
        l2 = l2->prox;
    }


    destroiL(&l1);
    destroiL(&l2);

    return;

}






#endif // _HPP_LISTA_DINAMICA









