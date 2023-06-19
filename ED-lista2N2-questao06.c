/*
** Fun��o : criação de um programa em c que use funções para manejar uma lista de compras 
** Autor : Marcos Barbosa Vieira Filho - P3 CC Unip� - RGM 30174503
** Data : 19/06/2023
** Observa��es:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char nome[100];
    int quantidade;
    struct Item* proximo;
} Item;

Item* criarItem(const char* nome, int quantidade) {
    Item* novoItem = (Item*)malloc(sizeof(Item));
    if (novoItem == NULL) {
        printf("Erro de alocação de memória.\n");
        return NULL;
    }
    strncpy(novoItem->nome, nome, 99);
    novoItem->quantidade = quantidade;
    novoItem->proximo = NULL;
    return novoItem;
}

void inserirItem(Item** lista, const char* nome, int quantidade) {
    Item* novoItem = criarItem(nome, quantidade);
    if (novoItem == NULL) {
        return;
    }

    if (*lista == NULL) {
        *lista = novoItem;
    } else {
        Item* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoItem;
    }

    printf("Item adicionado à lista de compras.\n");
}

void removerItem(Item** lista, const char* nome) {
    if (*lista == NULL) {
        printf("A lista de compras está vazia.\n");
        return;
    }

    Item* anterior = NULL;
    Item* atual = *lista;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                *lista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Item removido da lista de compras.\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("O item \"%s\" não está na lista de compras.\n", nome);
}

void consultarItem(const Item* lista, const char* nome) {
    const Item* atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Item: %s\n", atual->nome);
            printf("Quantidade: %d\n", atual->quantidade);
            return;
        }
        atual = atual->proximo;
    }

    printf("O item \"%s\" não está na lista de compras.\n", nome);
}

void mostrarLista(const Item* lista) {
    if (lista == NULL) {
        printf("A lista de compras está vazia.\n");
        return;
    }

    printf("Lista de compras:\n");
    const Item* atual = lista;
    while (atual != NULL) {
        printf("- Item: %s, Quantidade: %d\n", atual->nome, atual->quantidade);
        atual = atual->proximo;
    }
}

void liberarLista(Item** lista) {
    Item* atual = *lista;
    while (atual != NULL) {
        Item* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *lista = NULL;
}

int main() {
    Item* listaCompras = NULL;
    int opcao;

    while (1) {
        printf("\n----- Lista de Compras -----\n");
        printf("Selecione a opçãodesejada:\n");
printf("1 - Inserir item\n");
printf("2 - Remover item\n");
printf("3 - Consultar item\n");
printf("4 - Mostrar lista de compras\n");
printf("5 - Encerrar programa\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: {
            char nome[100];
            int quantidade;
            printf("Digite o nome do item: ");
            scanf("%s", nome);
            printf("Digite a quantidade: ");
            scanf("%d", &quantidade);
            inserirItem(&listaCompras, nome, quantidade);
            break;
        }
        case 2: {
            char nome[100];
            printf("Digite o nome do item a ser removido: ");
            scanf("%s", nome);
            removerItem(&listaCompras, nome);
            break;
        }
        case 3: {
            char nome[100];
            printf("Digite o nome do item a ser consultado: ");
            scanf("%s", nome);
            consultarItem(listaCompras, nome);
            break;
        }
        case 4:
            mostrarLista(listaCompras);
            break;
        case 5:
            liberarLista(&listaCompras);
            printf("Encerrando o programa.\n");
            return 0;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }
}

return 0;
}