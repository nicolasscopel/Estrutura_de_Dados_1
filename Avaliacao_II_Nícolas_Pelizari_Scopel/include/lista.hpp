#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA



struct No
{
    int dado;
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

void mostraL(No **lista, string l)
{
    No *n = *lista;

    cout  << l << ":{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

///insere no início da lista
bool insereInicioL(No **lista, int valor)
{

    No *novo = new No(); // aloca memória para o nó
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

///Insere um valor no final da lista
void insereFinalL(No **lista, int valor)
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



///retorna o valor do primeiro elemento da lista SEM removê-lo
int leInicioL(No **lista)
{
    int dado =0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

///retorna o valor do ULTIMO elemento da lista SEM removê-lo
int leFinalL(No **lista)
{
    int dado = 0;

    No *N = *lista;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado

    while(N->prox != NULL)
    {
        N = N->prox;
    }

    dado = N->dado;

    return dado;
}

///retorna o valor do primeiro elemento da lista e REMOVE o elemento
int removeInicioL(No **lista)
{
    No* aux;
    int dado;

    if(vaziaL(lista) == false)
    {
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado
        aux = *lista; //pega a referenccia do primeiro nó, o qual será removido

        *lista = (*lista)->prox; //atualiza o início da lista para o próximo elemento

        delete aux;
    }

    return dado;
}

///retorna o valor do ultimo elemento da lista e REMOVE o elemento
int removeFinalL(No **lista)
{
    No *anterior = NULL;
    No *fim = *lista;
    int dado = 0;

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



///remover um nó da lista com um valor específico
bool removeL(No **lista, int valor)
{
    No *anterior = NULL;
    No *atual = *lista;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual!=NULL && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar -> atual tem o endereço do elemento para excluir
    if(atual == NULL) /// se atual é NULL -> não encontrou
        return false;

    if (anterior == NULL)
    {
        /// o elemento a ser excluído está no início da lista
        *lista = atual->prox;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
    }

    /// libera a memória do elemento
    delete(atual);
    return true;
}


No* buscaL(No **lista, int valor)
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

    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        n = n->prox;
        cont++;
    }

    return cont;
}

///verifica se duas listas são iguais
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

///retorna o valor do dado armazenado em um nó da lista, com base na posição passada por parâmetro
///se posição=0, a função deve retornar o valor do primeiro nó da lista
///se posição=1, a função deve retornar o valor do segundo nó da lista

int lePosicao(No **lista, int posicao)
{
    int cont = 0;

    No *n = *lista;

    while(cont != posicao)
    {
        n = n->prox;
        cont++;
    }
     int valor = n->dado;

     return valor;

}

///União de duas listas
void uniao(No **lista1, No **lista2, No **listaSaida)
{
    No *l1 = *lista1;
    No *l2 = *lista2;

    int valor;

    while(l1 != NULL)
    {
        valor = l1->dado;
        insereFinalL(listaSaida,valor);
        l1 = l1->prox;
    }
    while(l2 != NULL)
    {
        valor = l2->dado;
        insereFinalL(listaSaida,valor);
        l2 = l2->prox;
    }


    destroiL(&l1);
    destroiL(&l2);

    return;

}

///Intersecao de duas listas
void interseccaoListas(No **lista1, No **lista2, No **listaSaida)
{
    No *l1 = *lista1;
    No *l2 = *lista2;
    No *ver = new No();

    int valor;

    while(l1 != NULL)
    {
        valor = l1->dado;

        while(l2 != NULL)
        {
            if(valor == l2->dado && buscaL(listaSaida,valor) == NULL)
            {
                insereInicioL(listaSaida,valor);
                break;

            }
            l2 = l2->prox;
        }

        l2 = *lista2;

        l1 = l1->prox;
    }

    destroiL(&l1);
    destroiL(&l2);

    return;

}

///Insere um valor na posicao informada
bool inserePosicao(No** lista, int pos, int valor)
{

    if (totalL(lista) - 1 < pos || pos < 0)
    {
        cout << "teste false";
        return false;
    }

    No *anterior = NULL;
    No *atual = *lista;
    No *novo = new No();
    int cont = 0;

    novo->dado = valor;

    while(cont != pos  && atual != NULL)
    {
        anterior = atual;
        atual = atual->prox;
        cont++;
    }
    cout << " teste";

    if (anterior == NULL)
    {
        novo->prox = atual;
        *lista = novo; //PARA ALTERAR O PONTEIRO DA LISTA PARA O NOVO NO INICIO
        cout << " teste2";
        return true;
    }
    else
    {
        cout << " teste3";
        anterior->prox = novo;
        novo->prox = atual;
        return true;
    }

}

///Insere valores ordenados crescentemente
void insereOrdenado(No** lista, int valor)
{

    No *anterior = NULL;
    No *atual = *lista;
    No *novo = new No();

    novo->dado = valor;

    while(atual != NULL && valor > atual->dado)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if(anterior == NULL)
    {
        novo->prox = atual;
        *lista = novo;
        cout << " teste inicio ";
        return;
    }
    if(atual == NULL)
    {
        cout << " teste meio ";
        anterior->prox = novo;
        novo->prox = NULL;

        return;
    }
    else
    {
        anterior->prox = novo;
        novo->prox = atual;
        cout << " teste fim ";
        return;
    }


}

int verificaOrdem(No** lista)
{
    No *anterior = *lista;
    No *atual = *lista;
    atual = atual->prox;
    int chave;

    if(anterior->dado <= atual->dado)
    {
        while(atual->prox != NULL)
        {
            anterior = atual;
            atual = atual->prox;

            if(anterior->dado > atual->dado)
            {
                chave = 2;
                return chave;
            }
            chave = 0;
        }
    }

    if(anterior->dado >= atual->dado)
    {

        while(atual->prox != NULL)
        {
            anterior = atual;
            atual = atual->prox;

            if(anterior->dado < atual->dado)
            {
                chave = 2;
                return chave;
            }
            chave = 1;
        }
    }

    return chave;
}

void ordenarL(No** lista)
{

    if(vaziaL(lista))
    {
        cout << "\nNao é possivel ordenar uma lista vazia!";
        return;
    }

    No *atual = *lista;
    No *proximo;
    int valor;

    while(verificaOrdem(lista) == 2)
    {

        proximo = atual->prox;

        if(atual->dado > proximo->dado)
        {
            valor = proximo->dado;
            proximo->dado = atual->dado;
            atual->dado = valor;

        }

        atual = atual->prox;

        if(atual->prox == NULL)
        {
            atual = *lista;

        }
    }



}

void mesclar(No **lista1, No **lista2, No **lista3, int qtd)
{

    int quantidadel1;
    quantidadel1 = totalL(lista1);

    int cont = 0;
    No *l1 = *lista1;
    No *l2 = *lista2;

    int valor;

    if(quantidadel1 < qtd || qtd < 0)
    {
        return;
    }
    else if(quantidadel1 == qtd)
    {
        uniao(lista1,lista2,lista3);
    }
    else
    {
        while(cont < qtd)
        {
            valor = l1->dado;
            insereFinalL(lista3,valor);
            l1 = l1->prox;
            cont++;
        }
        while(l2)
        {
            valor = l2->dado;
            insereFinalL(lista3,valor);
            l2 = l2->prox;
        }

        while(l1)
        {
            valor = l1->dado;
            insereFinalL(lista3,valor);
            l1 = l1->prox;
        }




    }

    destroiL(&l1);
    destroiL(&l2);



}







#endif // _HPP_LISTA_DINAMICA









