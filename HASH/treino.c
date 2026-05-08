#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
   ---------------------------------------------------------
   TAD: TABELA DE DISPERSÃO (HASH)
   Seguindo: Waldemar Celes e José Lucas Rangel (2004)
   ---------------------------------------------------------
*/

// Estrutura do Nó (Privada ao arquivo .c)
typedef struct no {
    char nome[50];
    struct no* prox;
} No;

// Estrutura da Tabela Hash (O "Tipo Abstrato")
typedef struct hash {
    int tam;
    No** vet; // Vetor de ponteiros para No (Celes, pág. 312)
} Hash;

// --- FUNÇÃO HASH ---
// Soma os valores ASCII. No livro, os autores sugerem 
// processar a string para gerar o índice.
static int hash_funcao(int tam, char* s) {
    int i, total = 0;
    for (i = 0; s[i] != '\0'; i++)
        total += s[i];
    return (total % tam);
}

// --- OPERAÇÕES DO TAD ---

// Cria a tabela alocando o vetor dinamicamente
Hash* hash_cria(int tam) {
    int i;
    Hash* h = (Hash*)malloc(sizeof(Hash));
    h->tam = tam;
    h->vet = (No**)malloc(tam * sizeof(No*));
    for (i = 0; i < tam; i++) 
        h->vet[i] = NULL;
    return h;
}

// Insere no início da lista (mais eficiente)
void hash_insere(Hash* h, char* nome) {
    int hsh = hash_funcao(h->tam, nome);
    No* novo = (No*)malloc(sizeof(No));
    
    strcpy(novo->nome, nome);
    novo->prox = h->vet[hsh]; // O novo nó aponta para o antigo início
    h->vet[hsh] = novo;       // A tabela agora aponta para o novo nó
}

// Imprime a tabela mostrando o encadeamento
void hash_imprime(Hash* h) {
    int i;
    printf("\n--- ESTADO ATUAL DA TABELA ---\n");
    for (i = 0; i < h->tam; i++) {
        printf("[%2d]: ", i);
        No* aux = h->vet[i];
        while (aux != NULL) {
            printf("%s -> ", aux->nome);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
}

// Persistência: Salva todos os nomes em arquivo TXT/CSV
void hash_salva(Hash* h, char* arquivo) {
    FILE* fp = fopen(arquivo, "w");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }
    for (int i = 0; i < h->tam; i++) {
        No* aux = h->vet[i];
        while (aux != NULL) {
            fprintf(fp, "%s\n", aux->nome);
            aux = aux->prox;
        }
    }
    fclose(fp);
    printf("\n[✔] Dados salvos em '%s'.", arquivo);
}

// Persistência: Carrega nomes do arquivo e insere na tabela
void hash_carrega(Hash* h, char* arquivo) {
    FILE* fp = fopen(arquivo, "r");
    if (fp == NULL) return; // Se não existe, apenas ignora
    
    char buffer[50];
    while (fscanf(fp, "%49s", buffer) == 1) {
        hash_insere(h, buffer);
    }
    fclose(fp);
    printf("\n[✔] Dados carregados de '%s'.", arquivo);
}

// Libera toda a memória (Muito importante no livro do Celes)
void hash_libera(Hash* h) {
    int i;
    for (i = 0; i < h->tam; i++) {
        No* aux = h->vet[i];
        while (aux != NULL) {
            No* t = aux->prox;
            free(aux);
            aux = t;
        }
    }
    free(h->vet);
    free(h);
}

// --- PROGRAMA PRINCIPAL ---

int main() {
    // Definimos o tamanho como 31 (um número primo é melhor para dispersão)
    Hash* tabela = hash_cria(31);
    
    // Tenta carregar dados de execuções anteriores
    hash_carrega(tabela, "dados.txt");

    int opcao;
    char entrada[50];

    do {
        printf("\n\n1: Inserir Nome\n2: Imprimir Tabela\n0: Sair e Salvar\nEscolha: ");
        if (scanf("%d", &opcao) != 1) break;
        getchar(); // Limpa o \n do buffer

        if (opcao == 1) {
            printf("Digite o nome: ");
            scanf("%49s", entrada);
            hash_insere(tabela, entrada);
            printf("Inserido com sucesso!");
        } 
        else if (opcao == 2) {
            hash_imprime(tabela);
        }
    } while (opcao != 0);

    // Antes de fechar, salva e limpa a memória
    hash_salva(tabela, "dados.txt");
    hash_libera(tabela);

    printf("\nPrograma encerrado.\n");
    return 0;
}