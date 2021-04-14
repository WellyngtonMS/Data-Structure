#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "fila.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    TFila fila1, fila2, fila3;
    TipoItem item;
    FFVazia(&fila1);
    FFVazia(&fila2);
    int opcao;
    int n;
    do{
        system("cls");
        MSG_MENU();
        printf("\n\nDigite uma opção: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Quantos valores serão inseridos na lista: ");
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d valor: ", i);
                    scanf("%d", &item.Chave);
                    Enfileirar(item, &fila1);
                }
                system("PAUSE");
                break;
            case 2:
                printf("Digite o valor que deseja remover: ");
                scanf("%d", &item.Chave);
                Desenfileirar(&fila1, &item);
                system("PAUSE");
                break;
            case 3:
                Imprimir(&fila1);
                system("PAUSE");
                break;
            case 4:
                FFVazia(&fila1);
                printf("Quantos números serão inseridos na 1ª fila: ");
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d valor: ", i);
                    scanf("%d", &item.Chave);
                    Enfileirar(item, &fila1);
                }
                printf("Quantos números serão inseridos na 2ª fila: ");
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d valor: ", i);
                    scanf("%d", &item.Chave);
                    Enfileirar(item, &fila2);
                }
                verificaFilasIguais(&fila1, &fila2);
                system("PAUSE");
                break;
            case 5:
                printf("Qual a posição do n-ésimo valor a ser removido: ");
                scanf("%d", &n);
                removerNesimo(&fila1, n);
                system("PAUSE");
                break;
            case 6:
                FFVazia(&fila1);
                FFVazia(&fila2);
                FFVazia(&fila3);
                printf("Quantos números serão inseridos na 1ª fila: ");
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d valor: ", i);
                    scanf("%d", &item.Chave);
                    Enfileirar(item, &fila1);
                }
                printf("Quantos números serão inseridos na 2ª fila: ");
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d valor: ", i);
                    scanf("%d", &item.Chave);
                    Enfileirar(item, &fila2);
                }
                intersecaoFilas(&fila1, &fila2, &fila3);
                Imprimir(&fila3);
                system("PAUSE");
                break;
            case 7:
                FFVazia(&fila1);
                FFVazia(&fila2);
                FFVazia(&fila3);
                printf("Quantos números serão inseridos na 1ª fila: ");
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d valor: ", i);
                    scanf("%d", &item.Chave);
                    Enfileirar(item, &fila1);
                }
                printf("Quantos números serão inseridos na 2ª fila: ");
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d valor: ", i);
                    scanf("%d", &item.Chave);
                    Enfileirar(item, &fila2);
                }
                diferencaFilas(&fila1, &fila2, &fila3);
                Imprimir(&fila3);
                system("PAUSE");
                break;
            case 8:
                FFVazia(&fila1);
                printf("Quantos números serão inseridos na 1ª fila: ");
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d valor: ", i);
                    scanf("%d", &item.Chave);
                    Enfileirar(item, &fila1);
                }
                organizaCrescente(&fila1);
                Imprimir(&fila1);
                system("PAUSE");
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("\nERRO: Opção inválida!\n");
                system("PAUSE");
                break;
        }
    }while(opcao != 9);

    return 0;
}
