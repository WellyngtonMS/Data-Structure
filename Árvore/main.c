#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arvore.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    TArvore arv;
    Iniciar(&arv.raiz);
    TItem x;
    TCelula *aux;
    do{
        system("cls");
        MSG_MENU();
        printf("\n\nDigite uma opção: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite o valor que deseja inserir:\n");
                scanf("%d", &x.chave);
                Inserir(&arv.raiz, NULL, x);
                system("PAUSE");
                break;
            case 2:
                printf("Digite o valor que deseja remover:\n");
                scanf("%d", &x.chave);
                aux = Pesquisar(arv.raiz, x);
                Retirar(&arv, &aux);
                system("PAUSE");
                break;
            case 3:
                aux = Maximo(arv.raiz);
                if(aux == NULL){
                    printf("Árvore vazia!\n");
                }else{
                    printf("O maior valor encontrado na árvore foi %d\n", aux->item.chave);
                }
                system("PAUSE");
                break;
            case 4:
                aux = Minimo(arv.raiz);
                if(aux == NULL){
                    printf("Árvore vazia!\n");
                }else{
                    printf("O menor valor encontrado na árvore foi %d\n", aux->item.chave);
                }
                system("PAUSE");
                break;
            case 5:
                printf("Digite um valor para encontrar seu sucessor:\n");
                scanf("%d", &x.chave);
                aux = Pesquisar(arv.raiz, x);
                if(aux == NULL){
                    printf(">>>>> AVISO: O valor não existe na árvore ou é nulo! <<<<<\n");
                }else if(aux->dir == NULL && aux->esq == NULL){
                    printf("O valor informado não possui sucessor!\n");
                }
                else{
                    aux = Sucessor(aux);
                    printf("O sucessor de %d é %d\n", x.chave, aux->item.chave);
                }
                system("PAUSE");
                break;
            case 6:
                printf("Digite um valor para encontrar seu predecessor(antecessor):\n");
                scanf("%d", &x.chave);
                aux = Pesquisar(arv.raiz, x);
                if(aux == NULL){
                    printf(">>>>> AVISO: O valor não existe na árvore ou é nulo! <<<<<\n");
                }
                else if(aux->pai == NULL){
                    printf("O valor informado não possui predecessor(antecessor)!\n");
                }else{
                    aux = Predecessor(aux);
                    printf("O predecessor de %d é %d\n", x.chave, aux->item.chave);
                }
                system("PAUSE");
                break;
            case 7:
                Central(arv.raiz);
                printf("\n");
                system("PAUSE");
                break;
            case 8:
                printf("Digite o valor que deseja inserir:\n");
                scanf("%d", &x.chave);
                insereIterativo(&arv.raiz, NULL, x);
                system("PAUSE");
                break;
            case 9:
                imprimirOrdem(arv);
                system("PAUSE");
                break;
            case 10:
                printf("Ao liberar os nós da árvore, não será possível inserir mais nela!\n");
                system("PAUSE");
                liberaArvore(arv.raiz);
                exit(0);
                break;
            case 11:
                exit(0);
                break;
            default:
                printf("\nERRO: Opção inválida!\n");
                system("PAUSE");
                break;
        }
    }while(opcao != 11);

    return 0;
}
