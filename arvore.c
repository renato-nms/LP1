#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    void* info;
    struct No* esquerda;
    struct No* direita;
} Noarv;

Noarv* criar(void* valor){
    Noarv* novo = malloc(sizeof(Noarv));
    if(novo == NULL){
        return NULL;
    }
    novo->info = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}


Noarv* inserir(Noarv* raiz, void* info, int (*comparar)(const void *, const void *)) {
    if(raiz == NULL){
        return criar(info);
    }

    if(comparar(info,raiz->info) < 0) {
        raiz->esquerda = inserir(raiz->esquerda, info, comparar);
    } else {
        raiz->direita = inserir(raiz->direita, info, comparar);
    }
    return raiz;
}

Noarv* busca(Noarv* raiz, void *info){
    if(info == raiz->info){
        return raiz;
    } else if(info < raiz->info){
        raiz->esquerda = busca(raiz->esquerda,info);
    } else {
        raiz->direita = busca(raiz->direita,info);
    }
}

Noarv* altura(Noarv* raiz){
    if(raiz == NULL){
        return 0;
    }
    int altura_esquerda = altura(raiz->esquerda);
    int altura_direita = altura(raiz->direita);
    return (altura_esquerda > altura_direita ? altura_esquerda : altura_direita) + 1;
}

void imprimir_ordem(Noarv* raiz, void(*imprimir)(const void *)){
if(raiz == NULL){
    return NULL;
}
imprimir(raiz->info);
imprimir_ordem(raiz->esquerda, imprimir);
imprimir_ordem(raiz->direita, imprimir);
}

void liberar(Noarv * raiz, void (*destruir)(const void*)){
    if(raiz == NULL){
        return;
    }
    liberar(raiz->esquerda, destruir);
    liberar(raiz->direita, destruir);
    destruir(raiz->info);
    free(raiz);
}