typedef struct No{
    void* info;
    struct No* esquerda;
    struct No* direita;
} Noarv;


int vazia(void);

Noarv* criar(char c, Noarv* direita, Noarv* esquerda);

Noarv* inserir(Noarv* a, char c);

void imprimir(Noarv* a);


void liberar(Noarv* a);