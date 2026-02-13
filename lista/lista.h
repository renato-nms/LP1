typedef struct no{
    int valor;
    struct no* proximo;
} No;

void inserir_inicio(No** lista, int num);

void inserir_fim(No** lista, int num);

void imprimir(No* lista);