typedef struct{
    int Chave;
    char nome[50];
    /* outros componentes */
}TipoItem;

typedef struct celula{
    TipoItem item;
    struct celula* prox;
}TCelula;

typedef struct lista{
    TCelula* primeiro;
    TCelula* ultimo;
}TLista;

void FLVazia(TLista *Lista);
int Vazia(TLista Lista);
void Inserir(TipoItem x, TLista *Lista);
void Retirar(TCelula* p, TLista *Lista, TipoItem *Item);
void Imprimir(TLista Lista);
void ImprimirNomes(TLista Lista);
TCelula* Pesquisar(TipoItem item, TLista lista);
int verificaListas(TLista lista1, TLista lista2);
void insereOrdenadoCrescente(TLista *lista, TipoItem x);
void ImprimeIesima(TLista lista);
void RemoveIesima(TLista *lista);
void removerRepetidos(TLista *lista);
void MSG_MENU();
