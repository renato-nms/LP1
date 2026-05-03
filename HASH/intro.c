#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 31

typedef struct no{
    struct no* prox;
} No;

typedef struct{
    int tam;
    No* inicio;
} Lista;

void inicializa_lista(Lista* lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_lista(Lista* lista, int valor){
    No* novo (No*)malloc(sizeof(No));
    
    if (novo){
        novo->chave = valor;
        novo->prox = lista->inicio;
        lista->inicio = novo;
    } else {
        printf("erro ao alocar"); 
    }
}

int busca_lista(Lista* lista, int valor){
    No *aux = lista->inicio/
    while(aux != 0 && aux->chave != valor){
        aux = aux->prox;
        if(aux){
            return aux->chave;
            return 0;
        }
    }
}

void imprimir_lista(Lista* lista){
    No* aux = lista->inicio;
    printf(" Tamanho: %d: ",lista->tam)
    while(aux != 0){
        printf("Lista: %d\n",aux->chave);
        aux = aux->prox;
    }
    return 0;
}

void inicializa(int t[]){
  int i;
  for(i = 0; i < TAM; i++){
    inicializa_lista(&t[i]); 
  }
}

int funcaoHASH(int chave){
  return chave % TAM;
};

void insere(Lista t[], int valor){
   int id = funcaoHASH(valor);
  inserir_lista(*t[id], valor);
};

int busca(int t[],int valor){
  int id = funcaoHASH(valor);
  printf(("\nIndice gerado: %d\n",id);
  return busca_lista(&t[id], chave);
}


void imprimir(int t[]){
  for(int i = 0; i < TAM; i++){
      printf("%2d = ", i);
    imprimir_lista(&t[i])
  }
};

int main() {
  /*FILE* fp = fopen("arq.csv","r");
  
  char buffer[1024];
  
  while(fgets(buffer,sizeof(buffer),fp ) != NULL){
    printf("Lido: %s",buffer);
  }
  
  fclose(fp);*/
  int opcao, valor, retorno, tabela[TAM];
  inicializa(tabela);
  
  
  
  do{
    printf("\n\t0- Sair\n\t-1 Inserir\n\t2- Buscar\n\t3- Imprimir");
    scanf("%d",&opcao);
    
    switch(opcao){
      case 1:
      valor = rand() % 1000; // número entre 0 e 999
    printf("Valor gerado: %d\n", valor);
    insere(tabela, valor);
      break;
      
      case 2:
      srand(time(NULL));
      for(int i = 0; i < TAM; i++){
          printf("%d", valor % 100);
      }
      retorno = busca(tabela,valor);
      if(retorno != 0){
        printf("Valor encontrado: %d",retorno);
      } else {
        printf("Valor nao encontrado");
      }
      break;
      case 3:
      imprimir(tabela);
      break;
      
      default:
      printf("Opcao invalida\n");
      
    }
  }while(opcao != 0);
  
    return 0;
}