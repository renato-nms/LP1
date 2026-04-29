#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 31

void inicializa(int t[]){
  int i;
  for(i = 0; i < TAM; i++){
    t[i] = 0;
  }
}

int funcaoHASH(int chave){
  return chave % TAM;
}

void insere(int t[], int valor){
   int id = funcaoHASH(valor);
  while(t[id] != 0){
    id = funcaoHASH(id + 1);
  }  
  t[id] = valor;
}

int busca(int t[],int valor){
  int id = funcaoHASH(valor);
  while(t[id] != 0){
    if(t[id] == valor){
      return t[id];
    } else {
      id = funcaoHASH(id + 1);
    }
  }
  return -1;
}


void imprimir(int t[]){
  for(int i = 0; i < TAM; i++){
    printf("endereco: %d valor: %d\n",i, t[i]);
  }
}


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