#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criarNo(void* dado){
    No* novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro ao alocar memória para novo nó\n");
        return NULL;
}