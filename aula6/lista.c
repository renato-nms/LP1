/*
No repositório de LPI: Aula 6 Listas Genehricas inclui uma proposta de implementação que usa Listagen: Listagen_Produto.c.

    //1) Faça uma lista de produtos contendo 5 produtos.
   
    //2) Imprima a lista de produtos criada.
   
    //3) Crie uma lista filtrada a partir da lista inicial com produtos com preço menor que um valor (exemplo: R$ 3,00).
   
    //4) Crie uma lista que representa um carrinho de compras. Insira produtos (buscando pela chave pk) e suas quantidades.
   
    //5) Crie uma função para retornar o valor total dos produtos presentes no carrinho de compras.
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criarNo(void* dado) {
    No* novo = (No*)malloc(sizeof(No));
    if(novo != NULL){
        novo->info = dado;
        novo->proximo = NULL;
    } else {
        printf("Erro...");
    }
}

No* inserirInicio(No* lista, void* dado){
    No* novo = criarNo(dado);
    if(novo != NULL){
        novo->proximo = lista;
        return novo;
    }
}

No* inserirFim(No* lista, void* dado){
    No* novo = criarNo(dado);
    if(novo == NULL){
        return lista;
    }
    if(lista == NULL){
        return novo;
    }
    No* aux = lista;

    while(aux->proximo != NULL){
    aux = aux->proximo;
    }
    aux->proximo = novo;
    return lista;
}

void imprimirLista(No* lista, void (*imprime)(void*)){
    No* aux = lista;
    while(aux != NULL){
        imprime(aux->info);
        aux = aux->proximo;
    }
}