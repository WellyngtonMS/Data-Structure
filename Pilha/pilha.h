typedef int TipoChave;

typedef struct{
    int Chave;
    /* outros componentes */
} TipoItem;

typedef struct celula{
    TipoItem item;
    struct celula* prox;
} TCelula;

typedef struct{
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);
int Vazia(TPilha Pilha);
void Empilha(TipoItem x, TPilha *Pilha);
void Desempilha(TPilha *Pilha, TipoItem *Item);
int Tamanho(TPilha Pilha);
void comparar(char vet[], TPilha pilha);
char *infixaPosfixa(char *inf, TPilha pilha);
void somarNumeros();
void MSG_MENU();
