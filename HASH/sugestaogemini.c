#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 31 // Tamanho da tabela (número primo ajuda na dispersão)

// Definição da estrutura do Aluno (o Nó da nossa lista)
typedef struct aluno {
    int mat;           // Matrícula (chave primária)
    char nome[81];     // Nome do aluno
    char tel[13];      // Telefone
    char email[51];    // E-mail
    struct aluno* prox; // Ponteiro para o próximo aluno em caso de colisão
} Aluno;

static int hash(int mat) {
    return mat % N;
}

//Procurar aluno pela matricula
Aluno* hsh_busca(Aluno** tab, int mat){
    Aluno *p = tab[hash(mat)];

    while(p != NULL) {
        if(p->mat == mat)
        break;
        p = p->prox;
    }
    return p;
}

//Adiciona novo aluno ou atualiza ja existente
Aluno* hsh_insere(Aluno** tab, int mat, char* nome, char* tel, char* email){
 int id = hash(mat);
 Aluno* p = tab[hash(mat)];
 Aluno* ant = NULL;

 while(p != NULL) {
    if(p->mat == mat)
    break;
    p = p->prox;
 }
 if(p) {
    strcpy(p->nome,nome);
    strcpy(p->tel,tel);
    strcpy(p->email, email);
    return p;
 } else {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));

    if(!novo){
        return NULL;
    }

    novo->mat = mat;
    strcpy(novo->nome, nome);
    strcpy(novo->email, email);
    strcpy(novo->tel, tel);
    novo->prox = NULL;

     if(ant) {
    ant->prox = novo;
    } else {
    tab[id] = novo;
    }
     return novo;
}

}