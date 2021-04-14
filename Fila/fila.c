#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

void FFVazia(TFila *Fila){
    Fila->frente = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
}

int Vazia(TFila Fila){
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TipoItem x, TFila *Fila){
    Fila->tras->prox = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
}

void Desenfileirar(TFila *Fila, TipoItem *Item){
    TCelula* q;
    if (Vazia(*Fila)){
        printf(">>>>> Erro: Fila esta vazia! <<<<<\n");
        return;
    }
    q = Fila->frente;
    Fila->frente = Fila->frente->prox;
    *Item = Fila->frente->item;
    free(q);
}

void Imprimir(TFila *fila){
    TipoItem x;
    TFila faux;
    FFVazia(&faux);
    while(!Vazia(*fila)){
        Desenfileirar(fila, &x);
        printf("%d ", x.Chave);
        Enfileirar(x, &faux);
    }
    while(!Vazia(faux)){
        Desenfileirar(&faux, &x);
        Enfileirar(x, fila);
    }
    printf("\n");
}

//VERIFICA SE DUAS FILAS SÃO IGUAIS, INDENPENDENTE DA ORDEM DOS ELEMENTOs DE AMBAS
void verificaFilasIguais(TFila *fila1, TFila *fila2){
    TFila faux1, faux2, aux1, aux2;
    FFVazia(&faux1);
    FFVazia(&faux2);
    FFVazia(&aux1);
    FFVazia(&aux2);
    TipoItem item1, item2;
    int flag = 0;
    int x, y;
    int cont1 = 0, cont2 = 0;

    while(!Vazia(*fila1)){
        Desenfileirar(fila1, &item1);
        cont1++;
        Enfileirar(item1, &faux1);
    }
    while(!Vazia(*fila2)){
        Desenfileirar(fila2, &item2);
        cont2++;
        Enfileirar(item2, &faux2);
    }

    if(cont1 == cont2){
        while(!Vazia(faux1)){
            Desenfileirar(&faux1, &item1);
            x = item1.Chave;
            while(!Vazia(faux2)){
                Desenfileirar(&faux2, &item2);
                y = item2.Chave;
                if(x == y){
                    flag = flag+1;
                }
                Enfileirar(item2, &aux2);
            }
            while(!Vazia(aux2)){
                Desenfileirar(&aux2, &item2);
                Enfileirar(item2, &faux2);
            }
            Enfileirar(item1, &aux1);
        }
        while(!Vazia(aux1)){
            Desenfileirar(&aux1, &item1);
            Enfileirar(item1, fila1);
        }
        while(!Vazia(faux2)){
            Desenfileirar(&faux2, &item2);
            Enfileirar(item2, fila2);
        }

        if((flag == cont1) && (flag == cont2)){
            printf("As filas apresentam os mesmos elementos!\n");
        }
        else{
            printf("As filas nao apresentam os mesmos elementos!\n");
        }
    }
    else{
        printf("As filas nao apresentam os mesmos elementos!\n");
        while(!Vazia(faux1)){
            Desenfileirar(&faux1, &item1);
            Enfileirar(item1, fila1);
        }
        while(!Vazia(faux2)){
            Desenfileirar(&faux2, &item2);
            Enfileirar(item2, fila2);
        }
    }
}

//REMOVE O N-ÉSIMO ELEMENTO DE UMA FILA
void removerNesimo(TFila *fila, int posicao){
    int aux = 0;
    TFila faux;
    FFVazia(&faux);
    TipoItem item;
    while(!Vazia(*fila)){
        if(aux == posicao){
            Desenfileirar(fila, &item);
        }
        else{
            Desenfileirar(fila, &item);
            Enfileirar(item, &faux);
        }
        aux++;
    }
    while(!Vazia(faux)){
        Desenfileirar(&faux, &item);
        Enfileirar(item, fila);
    }
}

//FAZ A INTERSEÇÃO ENTRE DUAS FILAS, RESULTANDO NUMA TERCEIRA
void intersecaoFilas(TFila *f1, TFila *f2, TFila *f3){
    TFila faux1, faux2;
    FFVazia(&faux1);
    FFVazia(&faux2);
    TipoItem item1, item2;
    int x, y;

    while(!Vazia(*f1)){
        Desenfileirar(f1, &item1);
        x = item1.Chave;
        while(!Vazia(*f2)){
            Desenfileirar(f2, &item2);
            y = item2.Chave;
            if(x == y){
                Enfileirar(item1, f3);
                Enfileirar(item2, &faux2);
                while(!Vazia(*f2)){
                    Desenfileirar(f2, &item2);
                    Enfileirar(item2, &faux2);
                }
                break;
            }
            Enfileirar(item2, &faux2);
        }
        while(!Vazia(faux2)){
            Desenfileirar(&faux2, &item2);
            Enfileirar(item2, f2);
        }
        Enfileirar(item1, &faux1);
    }

    while(!Vazia(faux1)){
        Desenfileirar(&faux1, &item1);
        Enfileirar(item1, f1);
    }
}

//FAZ A DIFERENÇA ENTRE DUAS FILAS, RESULTANDO NUMA TERCEIRA
void diferencaFilas(TFila *f1, TFila *f2, TFila *f3){
    TFila faux1, faux2;
    FFVazia(&faux1);
    FFVazia(&faux2);
    TipoItem item1, item2;
    int x, y;
    int flag = 0;

    while(!Vazia(*f1)){
        Desenfileirar(f1, &item1);
        x = item1.Chave;
        while(!Vazia(*f2)){
            Desenfileirar(f2, &item2);
            y = item2.Chave;
            if(x == y){
                flag = 0;
                Enfileirar(item2, &faux2);
                while(!Vazia(*f2)){
                    Desenfileirar(f2, &item2);
                    Enfileirar(item2, &faux2);
                }
                break;
            }
            else{
                flag = 1;
            }
            Enfileirar(item2, &faux2);
        }
        if(flag == 1){
            Enfileirar(item1, f3);
        }
        while(!Vazia(faux2)){
            Desenfileirar(&faux2, &item2);
            Enfileirar(item2, f2);
        }
        Enfileirar(item1, &faux1);
    }

    while(!Vazia(faux1)){
        Desenfileirar(&faux1, &item1);
        Enfileirar(item1, f1);
    }
}

//COLOCA OS ELEMENTOS DE UMA FILA EM ORDEM CRESCENTE
void organizaCrescente(TFila *f1){
    TFila faux1, faux2;
    FFVazia(&faux1);
    FFVazia(&faux2);
    TipoItem item1, item2;
    TipoItem x;
    x.Chave = 10000;

    do{
        while(!Vazia(*f1)){
            Desenfileirar(f1, &item1);
            if(item1.Chave < x.Chave){
                x.Chave = item1.Chave;
            }
            Enfileirar(item1, &faux1);
        }
        Enfileirar(x, &faux2);

        while(!Vazia(faux1)){
            Desenfileirar(&faux1, &item2);
            if(item2.Chave != x.Chave){
                Enfileirar(item2, f1);
            }
        }
        x.Chave = 10000;
    }while(!Vazia(*f1));

    while(!Vazia(faux2)){
        Desenfileirar(&faux2, &item2);
        Enfileirar(item2, f1);
    }

}

void MSG_MENU(){
    printf("\n --- Menu:\n\n");
    printf("\t1. Inserir elemento\n");
    printf("\t2. Remover elemento\n");
    printf("\t3. Imprimir elementos\n");
    printf("\t4. Verificar 2 filas iguais\n");
    printf("\t5. Remover o elemento da n-ésima célula\n");
    printf("\t6. Interseção entre duas filas\n");
    printf("\t7. Diferença entre duas filas\n");
    printf("\t8. Ordena em ordem crescente\n");
    printf("\t9. Sair\n");
}
