#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    void* info;
    struct No* proximo;
} No;

No* criarNo(void* dado);
No* inserirInicio(No* lista, void* dado);
No* inserirFim(No* lista, void* dado);
void imprimirLista(No* lista, void (*imprime)(void*));  
void liberarLista(No* lista, void (*liberar)(void*));
