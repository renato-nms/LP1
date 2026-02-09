#ifndef __listagem_h__
#define __listagem_h__

typedef struct listagem {
    void* info;
    listagem* proximo;
} lista;

lista* criar_lista();
lista* inserir_lista(lista* l, void* info);
lista* percorrer_lista(lista* l);
