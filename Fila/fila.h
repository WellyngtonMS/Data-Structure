typedef struct TipoItem{
    int Chave;
    /* outros componentes */
}TipoItem;

typedef struct celula{
    TipoItem item;
    struct celula* prox;
}TCelula;

typedef struct TipoFila{
    TCelula* frente;
    TCelula* tras;
}TFila;

void FFVazia(TFila *Fila);
int Vazia(TFila Fila);
void Enfileirar(TipoItem x, TFila *Fila);
void Desenfileirar(TFila *Fila, TipoItem *Item);
void Imprimir(TFila *fila);
void verificaFilasIguais(TFila *fila1, TFila *fila2);
void removerNesimo(TFila *fila, int posicao);
void intersecaoFilas(TFila *f1, TFila *f2, TFila *f3);
void diferencaFilas(TFila *f1, TFila *f2, TFila *f3);
void organizaCrescente(TFila *f1);
void MSG_MENU();
