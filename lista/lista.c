// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"



void inserir_inicio(No **lista, int num){
    No* novo = malloc(sizeof(No));
    
    if(novo){
        novo-> valor = num;
        novo->proximo = *lista;
        *lista = novo;
    } else {
        printf("Erro...");
    }
}

void inserir_fim(No **lista, int num){
    No* aux;
    No* novo = malloc(sizeof(No));
    //conectar a estrututa
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        
    //verificar se é o primeiro
    if(novo == NULL){
        *lista = novo;
    } else {
        while(aux->proximo != NULL){
            aux = aux->proximo;
        aux->proximo = novo;
        }
    }
    
    } else {
        printf("Erro...");
    }
}
    

int main() {
    // Write C code here
    printf("Try programiz.pro");

    return 0;
}