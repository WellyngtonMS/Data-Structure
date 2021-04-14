#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "pilha.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    TPilha pilha1, pilha2;
    FPVazia(&pilha1);
    FPVazia(&pilha2);
    TipoItem item;
    char Pilha[50], Pilha2[100];
    int opcao;
    int n;
    do{
        system("cls");
        MSG_MENU();
        printf("\n\nDigite uma op��o: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Quantos valores ser�o inseridos na pilha: ");
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d valor: ", i);
                    scanf("%d", &item.Chave);
                    Empilha(item, &pilha1);
                }
                system("PAUSE");
                break;
            case 2:
                printf("Digite o valor que deseja desempilhar: ");
                scanf("%d", &item.Chave);
                Desempilha(&pilha1, &item);
                system("PAUSE");
                break;
            case 3:
                n = Tamanho(pilha1);
                printf("A pilha tem tamanho igual a %d.\n", n);
                system("PAUSE");
                break;
            case 4:
                printf("Digite a express�o de caracteres:\n");
                int i = 0;
                scanf("%s", &Pilha[i]);
                comparar(Pilha, pilha1);
                system("PAUSE");
                break;
            case 5:
                printf("Digite a nota��o infixa:\n");
                scanf("%s", &Pilha2[i]);
                printf("%s\n", infixaPosfixa(Pilha2, pilha2));
                system("PAUSE");
                break;
            case 6:
                somarNumeros();
                system("PAUSE");
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("\nERRO: Op��o inv�lida!\n");
                system("PAUSE");
                break;
        }
    }while(opcao != 7);

    return 0;
}
