#include <stdio.h>
#include <stdlib.h>
//FUNÇÃO NA TAD_LISTA  para permitir a gravaçaõ da lista em um arquivo usando fputc

 typedef struct No {
    char dado;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
} Lista;

    //ESCREVER BYTE
    void grava(Lista* lista, const char* "arquivo.txt"){
    FILE* file = fopen("arquivo.txt", "w");
    if (file == NULL) {
        exit(1);
    }
    char letra[20] = "programa em C";

   No* atual = lista->inicio;
    for(int i = 0; atual->dado != '\0'; atual = atual->prox) {
        fputc(atual->dado, file);
    }
    fclose(file);
}

 //ESCREVER STRING
 void grava_string(Lista* lista, const char* arquivo.txt){
    FILE* file = fopen("arquivo.txt", "w");
    if (file == NULL){
        exit(1);
    }
    char letra[20] = "Meu programa em C";
    No* atual = lista->inicio;
    while(atual != NULL){
        fputs(atual->dado, file);
        atual = atual->prox;
    }
    fclose(file);
}

//LER ARQUIVO STRING e conta linhas

void ler_string(Lista* lista, const char* nome_arquivo){
    FILE* file = fopen("arquivo.txt", "r");
    if(file == NULL){
        exit(1);
    }

    int buffer[1024];
    int contador = 0;
    
    while(fgets(buffer,sizeof(buffer),file) != NULL){
        printf("%s",buffer);
        contador++;
    }

    printf("quantidade de caracteres: %c",contador);
    fclose(file);
}