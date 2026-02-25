#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct {
    float x;
    float y;
} Ponto;

void imprimirPonto(void* dado) {
    Ponto* p = (Ponto*) dado;
    printf("Ponto: (%.2f, %.2f)\n", p->x, p->y);
}

void liberarPonto(void* dado) {
    free(dado);
}

int main() {

    No* lista = NULL;

    

    lista = inserirFim(lista, 1.0, 2.0);
    lista = inserirFim(lista, 3.0, 4.0);
    lista = inserirInicio(lista, 5.0, 6.0);
    lista = inserirInicio(lista, 7.0, 8.0);


    printf("Imprimindo lista:\n");
    imprimirLista(lista, imprimirPonto);

    liberarLista(lista, liberarPonto);

    return 0;
}
