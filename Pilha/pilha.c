#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void FPVazia(TPilha *Pilha){
    Pilha->topo = (TCelula*) malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;
}

int Vazia(TPilha Pilha){
    return (Pilha.topo == Pilha.fundo);
}

void Empilha(TipoItem x, TPilha *Pilha){
    TCelula* Aux;
    Aux = (TCelula*) malloc(sizeof(TCelula));
    Pilha->topo->item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;
}

void Desempilha(TPilha *Pilha, TipoItem *Item){
    TCelula* q;
    if(Vazia(*Pilha)){
        return;
    }
    q = Pilha->topo;
    Pilha->topo = q->prox;
    *Item = q->prox->item;
    free(q);
    Pilha->tamanho--;
}

int Tamanho(TPilha Pilha){
    return (Pilha.tamanho);
}

//AVALIAR UMA EXPRESSÃO ARITMÉTICA SEGUNDO A UTILIZAÇÃO DE (), [] E {}
void comparar(char vet[], TPilha pilha){
    TipoItem x;
    for(int i = 0; vet[i] != '\0'; i++){
        printf("%c\n", vet[i]);
    }

    for(int j = 0; vet[j] != '\0' ; j++){
        if(vet[j] == '{' || vet[j] == '(' || vet[j] == '['){
            x.Chave = vet[j];
            Empilha(x, &pilha);
        }
        else if(vet[j] == '}' || vet[j] == ')' || vet[j] == ']'){
            if((pilha.topo->prox->item.Chave == '{') && (vet[j] == '}')){
                Desempilha(&pilha, &x);
            }
            else if((pilha.topo->prox->item.Chave == '(') && (vet[j] == ')')){
                Desempilha(&pilha, &x);
            }
            else if((pilha.topo->prox->item.Chave == '[') && (vet[j] == ']')){
                Desempilha(&pilha, &x);
            }
            else{
                printf("ERRO. Expressão incorreta\n");
                return;
            }
        }
    }

    if(Vazia(pilha)){
        printf("Pilha vazia, todos elementos de abertura possuem seus respectivos fechamentos\n");
    }
    else{
        printf("ERRO. Expressão incorreta\n");
    }
}

//TRADUZIR EXPRESSÃO INFIXADA PARA UMA EXPRESSÃO PÓS-FIXADA
char *infixaPosfixa(char *inf, TPilha pilha){
    TipoItem x;
    int n = strlen(inf);
    char *posf;
    posf = malloc((n+1)*sizeof(char));
    x.Chave = inf[0];
    Empilha(x, &pilha);
    int j = 0;

    for(int i = 1; inf[i] != '\0'; i++){
        switch(inf[i]){
            TipoItem y;
            case '(':
                y.Chave = inf[i];
                Empilha(y, &pilha);
                break;
            case ')':
                Desempilha(&pilha, &y);
                while(y.Chave != '('){
                    posf[j++] = y.Chave;
                    Desempilha(&pilha, &y);
                }
                break;
            case '-':
                Desempilha(&pilha, &y);
                while(y.Chave != '('){
                    posf[j++] = y.Chave;
                    Desempilha(&pilha, &y);
                }
                Empilha(y, &pilha);
                y.Chave = inf[i];
                Empilha(y, &pilha);
                break;
            case '+':
                Desempilha(&pilha, &y);
                while(y.Chave != '('){
                    posf[j++] = y.Chave;
                    Desempilha(&pilha, &y);
                }
                Empilha(y, &pilha);
                y.Chave = inf[i];
                Empilha(y, &pilha);
                break;
            case '/':
                Desempilha(&pilha, &y);
                while((y.Chave != '(') && (y.Chave != '+') && (y.Chave != '-')){
                    posf[j++] = y.Chave;
                    Desempilha(&pilha, &y);
                }
                Empilha(y, &pilha);
                y.Chave = inf[i];
                Empilha(y, &pilha);
                break;
            case '*':
                Desempilha(&pilha, &y);
                while((y.Chave != '(') && (y.Chave != '+') && (y.Chave != '-')){
                    posf[j++] = y.Chave;
                    Desempilha(&pilha, &y);
                }
                Empilha(y, &pilha);
                y.Chave = inf[i];
                Empilha(y, &pilha);
                break;
            default: posf[j++] = inf[i];
        }
    }
    posf[j] = '\0';
    return posf;
}

//SOMA DE NÚMEROS GRANDES UTILIZANDO PILHAS
void somarNumeros(){
    TPilha p1, p2, p3;
    FPVazia(&p1);
    FPVazia(&p2);
    FPVazia(&p3);
    TipoItem z, w, soma, resto, aux;
    int *x, *y;
    int num, num1;
    printf("Digite a quantia de dígitos que seu primeiro número possui:\n");
    scanf("%d", &num);
    x = malloc(sizeof(int)*num);
    printf("Agora digite um número de cada vez:\n");
    for(int i = 0; i < num; i++){
        scanf("%d", &x[i]);
    }
    printf("Digite a quantia de dígitos que seu segundo número possui:\n");
    scanf("%d", &num1);
    printf("Agora digite um número de cada vez:\n");
    y = malloc(sizeof(int)*num1);
    for(int i = 0; i < num1; i++){
        scanf("%d", &y[i]);
    }

    for(int j = 0; j < num; j++){
        z.Chave = x[j];
        Empilha(z, &p1);
    }
    for(int i = 0; i < num1; i++){
        w.Chave = y[i];
        Empilha(w, &p2);
    }

    aux.Chave = 0;
    while((!Vazia(p1)) || (!Vazia(p2))){
        Desempilha(&p1, &z);
        Desempilha(&p2, &w);
        if(aux.Chave != 0){
            soma.Chave = z.Chave + w.Chave + aux.Chave;
            aux.Chave = 0;
        }
        else{
            soma.Chave = z.Chave + w.Chave;
        }
        if(soma.Chave >= 10){
            aux.Chave = soma.Chave/10;
            resto.Chave = soma.Chave%10;
            Empilha(resto, &p3);
        }
        else{
            Empilha(soma, &p3);
        }
        z.Chave = 0;
        w.Chave = 0;
    }
    printf("A soma dos dois valores é exatamente: ");
    while(!Vazia(p3)){
        Desempilha(&p3, &z);
        printf("%d", z.Chave);
    }
    printf("\n");
}

void MSG_MENU(){
    printf("\n --- Menu:\n\n");
    printf("\t1. Inserir elemento\n");
    printf("\t2. Remover elemento\n");
    printf("\t3. Tamanho da pilha\n");
    printf("\t4. Avaliar expressão numérica\n");
    printf("\t5. Traduzir uma expressão infixada para uma pós-fixada\n");
    printf("\t6. Somar números\n");
    printf("\t7. Sair\n");
}
