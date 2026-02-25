#ifndef PRODUTO_H
#define PRODUT0_H
#include "lista.h"

typedef struct prod {
    int pk;
    char nome[50];
    float preco;
} Produto;

typedef struct it {
    Produto* produto;
    int quantidade;
} Item;

void imprimeProduto(void* dado);

No* filtrarPreco(No* lista, float valor);

Produto* buscarProduto(No* lista, int pk);

void adicionarCarrinho(No** carrinho, Produto* produto, int qtd);

float calcularTotal(No* carrinho);

#endif