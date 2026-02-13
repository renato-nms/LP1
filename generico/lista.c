#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criarNo(void* dado) {
    No* novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }
    novo->info = dado;
    novo->proximo = NULL;
    return novo;
}

No* inserirInicio(No* lista, void* dado) {
    No* novo = criarNo(dado);
    if (novo == NULL)
        return lista;

    novo->proximo = lista;
    return novo;
}

No* inserirFim(No* lista, void* dado) {
    No* novo = criarNo(dado);
    if (novo == NULL)
        return lista;

    if (lista == NULL)
        return novo;

    No* aux = lista;
    while (aux->proximo != NULL)
        aux = aux->proximo;

    aux->proximo = novo;
    return lista;
}

void imprimirLista(No* lista, void (*imprime)(void*)) {
    No* aux = lista;
    while (aux != NULL) {
        imprime(aux->info);
        aux = aux->proximo;
    }
}

void liberarLista(No* lista, void (*liberar)(void*)) {
    No* aux = lista;
    while (aux != NULL) {
        No* temp = aux;
        liberar(aux->info);  // libera o dado
        aux = aux->proximo;
        free(temp);          // libera o nó
    }
}
