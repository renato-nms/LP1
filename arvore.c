#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    void* info;
    struct No* esquerda;
    struct No* direita;
} Noarv;

int nulo(Noarv* raiz){
    return raiz == NULL;
}

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
        return criar(raiz);
    }

    if(comparar(info,raiz->info) < 0) {
        raiz->esquerda = inserir(raiz->esquerda, info, comparar);
    } else {
        raiz->direita = inserir(raiz->direita, info, comparar);
    }
    return raiz;
}

Noarv* busca(Noarv* raiz, int(*condicao)(const void*)){
    if(raiz == NULL){
        return NULL;
    }   
    int cmp = condicao(raiz->info);
    if(cmp == 0){
        return raiz;
    }
    if(cmp < 0){
        return busca(raiz->esquerda,condicao);
    } else {
        return busca(raiz->direita,condicao);
    }
}

void map(Noarv* raiz, void(*operacao)(void *)){
    if(raiz == NULL){
        return;
    }
    operacao(raiz->info);
    map(raiz->esquerda,operacao);
    map(raiz->direita,operacao);
}

int altura(Noarv* raiz){
    if(raiz == NULL){
        return 0;
    }
    Noarv* esq = altura(raiz->esquerda);
    Noarv* dir = altura(raiz->direita);
    return(esq < dir ? esq : dir)+1;
}




void imprimir_ordem(Noarv* raiz, void(*imprimir)(const void *)){
if(raiz == NULL){
    return;
}

imprimir(raiz->info);
imprimir_ordem(raiz->esquerda, imprimir);
imprimir_ordem(raiz->direita, imprimir);
}

void liberar(Noarv * raiz, void (*destruir)(const void*)){
    if (raiz == NULL){
        return NULL;
    }
    liberar(raiz->esquerda,destruir);
    liberar(raiz->direita,destruir);
    destruir(raiz->info);
    free(raiz);
}