#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

void Iniciar(TCelula **no){
    *no = NULL;
}

TCelula *criaNo(TItem Item){
    TCelula *no = (TCelula*) malloc(sizeof(TCelula));
    no->pai = NULL;
    no->esq = NULL;
    no->dir = NULL;
    no->item = Item;
    return no;
}

void Inserir(TCelula **x, TCelula *pai, TItem Item){
    if((*x) == NULL){
        (*x) = criaNo(Item);
        if(pai != NULL)
            (*x)->pai = pai;
        return;
    }
    if((*x)->item.chave > Item.chave){
        Inserir(&(*x)->esq, (*x), Item);
        return;
    }
    if ((*x)->item.chave < Item.chave)
        Inserir(&(*x)->dir, (*x), Item);
    else
        printf("\n>>>>> AVISO: ELEMENTO %d JÁ EXISTE! <<<<<\n",Item.chave);
}

TCelula* Pesquisar(TCelula *x, TItem Item){
    if((x == NULL)||(x->item.chave == Item.chave))
        return x;
    if(Item.chave < x->item.chave)
        return Pesquisar(x->esq,Item);
    else if(Item.chave > x->item.chave)
        return Pesquisar(x->dir, Item);
}

void Central(TCelula *x){
    if (x != NULL){
     Central(x->esq);
     printf("%d ",x->item.chave);
     Central(x->dir);
    }
}

TCelula* Minimo(TCelula *x){
    if (x == NULL)
        return NULL;
    while(x->esq != NULL){
        x = x->esq;
    }
    return x;
}

TCelula* Maximo(TCelula *x){
    if (x == NULL)
        return NULL;
    while(x->dir != NULL){
        x = x->dir;
    }
    return x;
}

TCelula* Sucessor(TCelula *x){
    if(x == NULL)
        return NULL;
    if(x->dir != NULL)
        return Minimo(x->dir);
    TCelula *y = x->pai;
    while(y != NULL && x == y->dir){
        x = y;
        y = y->pai;
    }
    return y;
}

TCelula* Predecessor(TCelula *x){
    if(x == NULL)
        return x;
    if(x->esq != NULL)
        return Maximo(x->esq);
    TCelula* y = x->pai;
    while(y != NULL && x == y->esq){
        x = y;
        y = y->pai;
    }
    return y;
}

// Substitui subárvore enraizada no nó 'u' pela subárvore enraizada no nó 'v'.
void Transplante(TArvore *Arvore, TCelula **u, TCelula **v){
    if ((*u)->pai == NULL)
        Arvore->raiz = (*v);
    else if((*u) == (*u)->pai->esq)
        (*u)->pai->esq = (*v);
    else
        (*u)->pai->dir = (*v);
    if(*v != NULL)
        (*v)->pai = (*u)->pai;
}

// Retira um nó 'z' na árvore 'Arvore'.
void Retirar(TArvore *Arvore, TCelula **z){
    if (*z == NULL){
        printf("\n>>>>> AVISO: NÓ' \"z\" É' NULO! <<<<<\n");
        return;
    }
    if((*z)->esq == NULL)
        Transplante(Arvore, z, &(*z)->dir);
    else if((*z)->dir == NULL)
        Transplante(Arvore, z, &(*z)->esq);
    else{
        TCelula *y = Minimo((*z)->dir);
        if(y->pai != (*z)){
            Transplante(Arvore, &y, &y->dir);
            y->dir = (*z)->dir;
            y->dir->pai = y;
        }
        Transplante(Arvore, z, &y);
        y->esq = (*z)->esq;
        y->esq->pai = y;
    }
    free(*z);
    *z = NULL;
}

//INSERE ELEMENTO NA ÁRVORE MANUALMENTE, SEM USAR RECURSIVIDADE
void insereIterativo(TCelula **x, TCelula *pai, TItem Item){
    if(x == NULL){
        return;
    }
    TCelula * novo = criaNo(Item);
    if(novo == NULL){
        return;
    }
    if((*x) == NULL){
        (*x) = novo;
    }
    else{
        TCelula *atual = *x;
        TCelula *ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(Item.chave > atual->item.chave){
                atual = atual->dir;
            }
            else if(Item.chave < atual->item.chave){
                atual = atual->esq;
            }
            else{
                printf("\n>>>>> AVISO: ELEMENTO %d JÁ EXISTE! <<<<<\n",Item.chave);
                free(novo);
                return;
            }
        }

        if(Item.chave > ant->item.chave){
            ant->dir = novo;
        }
        else{
            ant->esq = novo;
        }
    }
}

//IMPRIME OS VALORES DA ÁRVORE SEGUINDO O PERCURSO EM ORDEM (ESQUERDA, RAIZ, DIREITA)
void imprimirOrdem(TArvore arv){
    TCelula *x = Minimo(arv.raiz);
    if(x == NULL){
        printf("Árvore vazia!\n");
    }else{
        printf("%d ", x->item.chave);
        while(x != NULL){
            x = Sucessor(x);
            if(x == NULL){
                return;
            }
            else printf("%d ", x->item.chave);
        }
        free(x);
    }
}

//LIBERA TODOS OS RECURSOS DA ÁRVORE, SEGUINDO A LÓGICA DO PERCURSO EM ORDEM
void liberaArvore(TCelula *x){
    if(x == NULL){
        return;
    }
    while(x != NULL){
        x = Minimo(x);
        free(x);
        x = NULL;
    }
}

void MSG_MENU(){
    printf("\n --- Menu:\n\n");
    printf("\t1. Inserir elemento\n");
    printf("\t2. Remover elemento\n");
    printf("\t3. Encontrar elemento máximo\n");
    printf("\t4. Encontrar elemento mínimo\n");
    printf("\t5. Encontrar elemento sucessor\n");
    printf("\t6. Encontrar elemento predecessor\n");
    printf("\t7. Caminhamento central\n");
    printf("\t8. Insere Iterativo\n");
    printf("\t9. Imprimir árvore Em ordem\n");
    printf("\t10. Liberar árvore\n");
    printf("\t11. Sair\n");
}
