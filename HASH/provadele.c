#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    int mat;
    char nome[50];
    char tel[20];
    char email[50];
    struct aluno* prox;
} Aluno;





int hsh_tamanho_bucket(Aluno** tab, int indice){
  int cont = 0, qtd = 0;
  Aluno* a = tab[indice];
    while(a != NULL){
        if(cont !=0){
            qtd++;
        }
        cont++;
        a = a->prox;
    }
    return qtd;

}


int hash_maior_colisao(Aluno** tab, int N){
    int maior_qtd = -1;
    int indice_maior = -1;

    for(int i = 0; i < N; i++){
        int atual_qtd = hsh_tamanho_bucket(tab, i);

        if(atual_qtd > maior_qtd){
            maior_qtd = atual_qtd;
            indice_maior = i;
        }
    }
    return indice_maior;
}

Aluno** hsh_clone(Aluno** tab, int TAM) {
    Aluno* novo = (Aluno**)malloc(TAM* sizeof(Aluno*));
    for(int i = 0; i < TAM; i++) {
        novo[i] = NULL;
        Aluno* aux = tab[i];

        while(aux != NULL){
            Aluno* novo_no = (Aluno*)malloc(sizeof(Aluno));

            novo_no->mat = aux->mat;
            strcpy(novo_no->nome, aux->nome);
            strcpy(novo_no->nome, aux->nome);
            strcpy(novo_no->nome, aux->nome);

            novo->prox = novo[i];
            novo[i] = novo_no;

            aux = aux->prox;
        }
    }
}

int main(void){

    printf("Hello world!");
    return 0;
}