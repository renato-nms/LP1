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

    // Criando primeiro ponto
    Ponto* p1 = malloc(sizeof(Ponto));
    p1->x = 1.0;
    p1->y = 2.0;

    // Criando segundo ponto
    Ponto* p2 = malloc(sizeof(Ponto));
    p2->x = 3.0;
    p2->y = 4.0;

    // Criando terceiro ponto
    Ponto* p3 = malloc(sizeof(Ponto));
    p3->x = 5.0;
    p3->y = 6.0;

    lista = inserirFim(lista, p1);
    lista = inserirFim(lista, p2);
    lista = inserirInicio(lista, p3);

    printf("Imprimindo lista:\n");
    imprimirLista(lista, imprimirPonto);

    liberarLista(lista, liberarPonto);

    return 0;
}
