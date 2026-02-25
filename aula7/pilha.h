typedef struct date {
    int dia, mes, ano;
} data;

typedef struct person {
    char nome[50];
    char sexo;
} pessoa;

typedef struct Node {
    pessoa p;
    data DataNas;
    struct Node* proximo;
} No;

// inserir, imprimir, empilhar, desempilhar

void dados_pessoa();

void imprimir(pessoa p);

No* empilhar(No* topo);

No* desempilhar(No* topo);
