#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 31

// Faltava o campo 'int chave' na struct para armazenar o valor
typedef struct no {
    int chave; 
    struct no* prox;
} No;

int funcaoHASH(int chave) {
    return chave % TAM;
} // Sem ';' após a função

void insere(int t[], int valor) {
    int id = funcaoHASH(valor);
    while(t[id] != 0){
        id = funcaoHASH(id + 1);
    }
    t[id] = valor;
}

int busca(int t[], int valor) {
    int id = funcaoHASH(valor);
    while(t[id] != 0){
        if(t[id] == valor){
            return t[id];
        } else {
            id = funcaoHASH(id + 1);
        }
        return -1;
    }
}

void imprimir(int t[]) {
    for (int i = 0; i < TAM; i++) {
        printf("endereco = %2d e valor = ", i, t[i]);
      // Faltava ';'
    }
}

int main() {
    int opcao, valor, retorno;
    int tabela[TAM]; // A tabela é um array de structs 'Lista'
    
    srand(time(NULL)); // Inicializa o random uma vez só no começo
    inicializa(tabela);
    
    do {
        printf("\n\t0- Sair\n\t1- Inserir\n\t2- Buscar\n\t3- Imprimir\n\tOpcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                valor = rand() % 1000;
                printf("Valor gerado: %d\n", valor);
                insere(tabela, valor);
                break;
                
            case 2:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                retorno = busca(tabela, valor);
                if (retorno != 0) {
                    printf("Valor encontrado: %d\n", retorno);
                } else {
                    printf("Valor nao encontrado\n");
                }
                break;
                
            case 3:
                imprimir(tabela);
                break;
                
            default:
                if(opcao != 0) printf("Opcao invalida\n");
        }
    } while (opcao != 0);
    
    return 0;
}