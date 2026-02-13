#ifndef __listagem_h__
#define __listagem_h__

typedef struct listagem {
    int valor;
    struct listagem* proximo;
} lista;

lista* criar_lista();
lista* inserir_lista(lista* l, int num);
lista* percorrer_lista(lista* l);
void imprimir(lista *l);