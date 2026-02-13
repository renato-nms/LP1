#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void inserir_inicio(No** lista, int num){
    No* novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    } else {
        printf("Erro...\n");
    }
}

void inserir_fim(No** lista, int num){
    No* novo = malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro...\n");
        return;
    }
    
    novo->valor = num;
    novo->proximo = NULL;

    if(*lista == NULL){
        *lista = novo;
        return;
    }

    No* aux = *lista; // Esta linha estava faltando!
    
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = novo;
}

void imprimir(No* lista){
    while(lista != NULL){
        printf("%d -> ", lista->valor);
        lista = lista->proximo;
    }
    printf("NULL\n");
}