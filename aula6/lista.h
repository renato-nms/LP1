#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    void* dado;
    struct no* prox;
} No;

No* criarNo(void* dado);
No* inserirInicio(No* lista, void* dado);
No* inserirFim(No* lista, void* dado);
void imprimirLista(No* lista, void (*imprime)(void*));
#endif