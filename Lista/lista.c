#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

void FLVazia(TLista *Lista){
    Lista->primeiro = (TCelula*)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->prox = NULL;
}

int Vazia(TLista Lista){
    return(Lista.primeiro == Lista.ultimo);
}

void Inserir(TipoItem x, TLista *Lista){
    Lista->ultimo->prox = (TCelula*)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = NULL;
}

void Retirar(TCelula* p, TLista *Lista, TipoItem *Item){
    /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
    TCelula* q;
    if(Vazia(*Lista) || p == NULL || p->prox == NULL){
        printf(">>>>> ERROR: Lista vazia ou posição não existe!!! <<<<<\n");
        return;
    }
    q = p->prox;
    *Item = q->item;
    p->prox = q->prox;
    if (p->prox == NULL)
        Lista->ultimo = p;
    free(q);
}

void Imprimir(TLista Lista){
    TCelula *aux;
    aux = Lista.primeiro->prox;
    while (aux != NULL){
        printf("%d\n", aux->item.Chave);
        aux = aux->prox;
    }
}

void ImprimirNomes(TLista Lista){
    TCelula *aux;
    aux = Lista.primeiro->prox;
    while (aux != NULL){
        printf("%s\n", aux->item.nome); // IMPRESSÃO PARA A FUNÇÃO INSERE ORDENADO CRESCENTE
        aux = aux->prox;
    }
}

//RETORNA UM PONTEIRO PARA A CÉLULA ANTERIOR A CÉLULA DO ELEMENTO PROCURADO
TCelula* Pesquisar(TipoItem item, TLista lista){
    TCelula* aux, *aux2;
    aux = lista.primeiro->prox;
    aux2 = lista.primeiro;
    if(!Vazia(lista)){
        while(aux != NULL){
            if(aux->item.Chave == item.Chave){
                return aux2;
            }
            aux = aux->prox;
            aux2 = aux2->prox;
        }
    }
    return aux2;
    free(aux);
    free(aux2);
}

//VERIFICA SE DUAS LISTAS SIMPLESMENTE ENCADEADAS SÃO IGUAIS
int verificaListas(TLista lista1, TLista lista2){
    TCelula *aux1, *aux2;
    aux1 = lista1.primeiro->prox;
    aux2 = lista2.primeiro->prox;
    if((Vazia(lista1) && (!Vazia(lista2))) || (Vazia(lista2) && !(Vazia(lista1)))){
        return 0;
    }
    while(aux1 != NULL || aux2 != NULL){
        if(aux1->item.Chave == aux2->item.Chave){
            aux1 = aux1->prox;
            aux2 = aux2->prox;
            //SE AS LISTAS FOREM IGUAIS
        }
        else{
            return 0;
        }
    }
    return 1;
}

//INSERE ELEMENTOS EM ORDEM CRESCENTE DE NOMES
void insereOrdenadoCrescente(TLista *lista, TipoItem x){
    TCelula *aux1 = lista->primeiro->prox;
    TCelula *aux2 = lista->primeiro;

    if(Vazia(*lista)){
        Inserir(x, lista);
    }
    else if(strcmp(x.nome, lista->ultimo->item.nome) > 0){
        Inserir(x, lista);
    }
    else{
        while(aux1 != NULL){
            if(strcmp(x.nome, aux1->item.nome) > 0){
                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }
            else if(strcmp(x.nome, aux1->item.nome) <= 0){
                TCelula *novo = (TCelula*)malloc(sizeof(TCelula));
                strcpy(novo->item.nome, x.nome);
                novo->prox = aux2->prox;
                aux2->prox = novo;
                break;
            }
        }
    }
}

//IMPRIME OS DADOS DA I-ÉSIMA CÉLULA DA LISTA
void ImprimeIesima(TLista lista){
    int iesima;
    printf("Digite a posição do elemento no qual deseja imprimir: \n");
    scanf("%d", &iesima);
    int i = 0;
    TCelula *aux = lista.primeiro->prox;

    while(i < iesima){
        if(aux->prox != NULL){
            aux = aux->prox;
        }
        else{
            printf("Posição não existe!\n");
            break;
        }
        i++;
    }
    if(i == iesima){
        printf("O elemento da posição %d é %d\n", iesima, aux->item.Chave);
    }
    free(aux);
}

//REMOVE OS DADOS DA I-ÉSIMA CÉLULA DA LISTA
void RemoveIesima(TLista *lista){
    int iesima;
    printf("Digite a posição do elemento no qual deseja remover: \n");
    scanf("%d", &iesima);
    int i = 0;
    TCelula *aux = lista->primeiro->prox;
    TCelula *aux2;
    TipoItem item;

    while(i < iesima){
        if(aux->prox != NULL){
            aux = aux->prox;
        }
        else{
            printf("Posição não existe!\n");
            break;
        }
        i++;
    }
    if(i == iesima){
        aux2 = Pesquisar(aux->item, *lista);
        Retirar(aux2, lista, &item);
    }
    free(aux2);
}

//REMOVE OS ELEMENTOS REPETIDOS DA LISTA
void removerRepetidos(TLista *lista) {
    TCelula *atual = lista->primeiro;
    TCelula *anterior;

    while(atual->prox != NULL){
        if(atual->item.Chave == atual->prox->item.Chave){
            anterior->prox = atual->prox;
        }else{
             anterior = atual;
        }
        atual = atual->prox;
    }
}

void MSG_MENU(){
    printf("\n --- Menu:\n\n");
    printf("\t1. Inserir elemento\n");
    printf("\t2. Inserir elemento em ordem crescente de Nomes\n");
    printf("\t3. Remover elemento\n");
    printf("\t4. Imprimir elementos\n");
    printf("\t5. Imprimir Nomes (p/ opção2)\n");
    printf("\t6. Imprimir os dados da i-ésima célula\n");
    printf("\t7. Remover o elemento da i-ésima célula\n");
    printf("\t8. Remover os elementos repetidos\n");
    printf("\t9. Verificar se 2 listas são iguais\n");
    printf("\t10. Sair\n");
}

