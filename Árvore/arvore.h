typedef struct item{
    int chave;
} TItem;

typedef struct celula{
    TItem item;
    struct celula *pai;
    struct celula *esq;
    struct celula *dir;
} TCelula;

typedef struct arvore{
    TCelula *raiz;
}TArvore;

void Iniciar(TCelula **no);
TCelula *criaNo(TItem Item);
void Inserir(TCelula **x, TCelula *pai, TItem Item);
TCelula* Pesquisar(TCelula *x, TItem Item);
void Central(TCelula *x);
TCelula* Minimo(TCelula *x);
TCelula* Maximo(TCelula *x);
TCelula* Sucessor(TCelula *x);
TCelula* Predecessor(TCelula *x);
void Transplante(TArvore *Arvore, TCelula **u, TCelula **v);
void Retirar(TArvore *Arvore, TCelula **z);
void insereIterativo(TCelula **x, TCelula *pai, TItem Item);
void imprimirOrdem(TArvore arv);
void liberaArvore(TCelula *x);
void MSG_MENU();
