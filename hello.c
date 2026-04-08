#include <stdio.h>
#include <stdlib.h>



typedef struct No{
    void* valor;
    struct No* direita;
    struct No* esquerda;
} Noarv;

// criar, inserir, imprimir, liberar

Noarv* cria(void* info){
    Noarv* novo = malloc(sizeof(Noarv));
    if(novo == NULL){
        novo->valor = info;
        novo->direita = NULL;
        novo->esquerda = NULL;
    }
}

Noarv* inserir(Noarv* raiz, void* info, int(*compara)(const void*, const void*)){
    if(raiz == NULL){
        return criar(info);
    }
    else {
    if(compara(info,raiz->valor) < 0){
        raiz->esquerda = inserir(raiz->esquerda,info);
    } else {
        raiz->direita = inserir(raiz->direita,info);
    }
}
    return raiz;
}

Noarv* imprimir(Noarv* raiz, void(*imprime)(const void*)){
    imprimir(raiz->esquerda,imprime);
    imprimir(raiz->direita,imprime);
    imprimir(raiz->valor);
}

void liberar(Noarv* raiz,void(*destruir)(const void*)){
    liberar(raiz->esquerda,destruir);
    liberar(raiz->direita,destruir);
    destruir(raiz->valor);
    free(raiz);

}


int main(void) {


    return 0;
}