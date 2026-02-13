#include <stdio.h>
#include <stdlib.h>
#include "listagem.h"

lista* criar_lista() {
    return NULL;
}

lista* inserir_lista(lista* l, int num){
 lista* novo = malloc(sizeof(lista));

 if(novo == NULL) {
    printf("Erro ao alocar memoria\n");
 }
    novo->valor = num;
    novo->proximo = l;
    l = novo;
    return l;
}

lista* percorrer_lista(lista* l){
    lista* novo = malloc(sizeof(lista));
    
    if(l == NULL){
        l = novo;
        return l;
    }
    lista* aux = l;

    while(aux->proximo != NULL) {
        aux = aux->proximo;
    }
}

