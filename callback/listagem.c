#include <stdio.h>
#include <stdlib.h>
#include "listagem.h"

listagem* criar_listagem() {
    return NULL;
}

listagem* inserir_listagem(listagem* lista, int num){
 listagem* novo = malloc(sizeof(listagem));

 if(novo == NULL) {
    printf("Erro ao alocar memoria\n");
 }
    novo->valor = num;
    novo->proximo = lista;
    lista = novo;
    return lista;
}

listagem* percorrer_listagem(listagem* lista){
    listagem* novo = malloc(sizeof(listagem));
    
    if(lista == NULL){
        return novo;
    }
    listagem* aux = lista;

    while(aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = novo;
    return lista;
}

