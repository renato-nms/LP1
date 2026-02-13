#include <stdlib.h>
#include "lista.h"
#include <stdio.h>

int main(void){
    No* lista = NULL;
    inserir_inicio(&lista, 10);
    inserir_inicio(&lista, 20);
    inserir_fim(&lista, 30);
    imprimir(lista);
    return 0;
}