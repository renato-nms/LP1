#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

void imprimeProduto(void* dado){
    Produto* p = (Produto*) dado;

    printf("PK: %d | Nome: %s | Preco: %2.f\n", p->pk, p->nome, p->preco);
}

No* filtrarPreco(No* lista, float valor){
    No* novaLista = NULL;
    No* aux = lista;

    while(aux != NULL){
        Produto* p = (Produto*) aux->info;
        if(p->preco < valor){
            novaLista = inserirInicio(novaLista,p);
        }
        aux = aux->proximo;
    }
    return novaLista;
}