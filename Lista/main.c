#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "lista.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    TLista lista1, lista2;
    TCelula *aux;
    TipoItem item;
    FLVazia(&lista1);
    FLVazia(&lista2);
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
                    Inserir(item, &lista1);
                }
                system("PAUSE");
                break;
            case 2:
                printf("Quantos nomes serão inseridos na lista: ");
                fflush(stdin);
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d nome: ", i);
                    fflush(stdin);
                    fgets(item.nome, 49, stdin);
                    insereOrdenadoCrescente(&lista1, item);
                }
                system("PAUSE");
                break;
            case 3:
                printf("Digite o valor que deseja remover: ");
                scanf("%d", &item.Chave);
                aux = Pesquisar(item, lista1);
                Retirar(aux, &lista1, &item);
                system("PAUSE");
                break;
            case 4:
                Imprimir(lista1);
                system("PAUSE");
                break;
            case 5:
                ImprimirNomes(lista1);
                system("PAUSE");
                break;
            case 6:
                ImprimeIesima(lista1);
                system("PAUSE");
                break;
            case 7:
                RemoveIesima(&lista1);
                system("PAUSE");
                break;
            case 8:
                removerRepetidos(&lista1);
                system("PAUSE");
                break;
            case 9:
                FLVazia(&lista1);
                printf("Quantos nomes serão inseridos na 1ª lista: ");
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d valor: ", i);
                    scanf("%d", &item.Chave);
                    Inserir(item, &lista1);
                }
                printf("Quantos nomes serão inseridos na 2ª lista: ");
                scanf("%d", &n);
                for(int i = 1; i <= n; i++){
                    printf("Digite o %d valor: ", i);
                    scanf("%d", &item.Chave);
                    Inserir(item, &lista2);
                }
                int x = verificaListas(lista1, lista2);
                if(x == 0){
                    printf("São diferentes.\n");
                }
                else printf("As listas são iguais.\n");
                system("PAUSE");
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("\nERRO: Opção inválida!\n");
                system("PAUSE");
                break;
        }
    }while(opcao != 10);

    return 0;
}
