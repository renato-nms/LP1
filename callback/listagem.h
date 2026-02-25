#ifndef __listagem_h__
#define __listagem_h__

typedef struct listagem {
    int valor;
    struct listagem* proximo;
} listagem;

listagem* criar_listagem();
listagem* inserir_listagem(listagem* lista, int num);
listagem* percorrer_listagem(listagem* lista);
void imprimir(listagem *lista);