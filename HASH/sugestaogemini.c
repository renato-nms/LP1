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

// 4. CLONE (Cópia profunda conforme o quadro)
Aluno** hsh_clone(Aluno** tab, int tam) {
    Aluno** tbc = (Aluno**)malloc(tam * sizeof(Aluno*));
    for (int id = 0; id < tam; id++) {
        tbc[id] = NULL;
        Aluno* p = tab[id];
        while (p != NULL) {
            Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
            novo->mat = p->mat;
            strcpy(novo->nome, p->nome);
            strcpy(novo->tel, p->tel);
            strcpy(novo->email, p->email);
            // Insere no início da nova tabela (mais simples)
            novo->prox = tbc[id];
            tbc[id] = novo;
            p = p->prox;
        }
    }
    return tbc;
}

// 5. EXPORTA ARQUIVO (Simplificado para ser fiel sem ponteiro de função)
int hsh_salva_arquivo(Aluno** tab, char* filename) {
    FILE* fp = fopen(filename, "w"); // Abre para escrita de texto
    if (!fp) return 0;

    for (int i = 0; i < N; i++) {
        Aluno* p = tab[i];
        while (p != NULL) {
            // Salva os dados separados por ponto-e-vírgula (padrão CSV)
            fprintf(fp, "%d;%s;%s;%s\n", p->mat, p->nome, p->tel, p->email);
            p = p->prox;
        }
    }
    fclose(fp);
    return 1;
}

// 6. IMPORTA ARQUIVO (Reconstrói a tabela a partir do disco)
int hsh_carrega_arquivo(Aluno** tab, char* filename) {
    FILE* fp = fopen(filename, "r"); // Abre para leitura de texto
    if (!fp) return 0;

    int m;
    char n[81], t[13], e[51];
    // Lê enquanto encontrar o formato definido no fprintf
    while (fscanf(fp, "%d;%[^;];%[^;];%s\n", &m, n, t, e) == 4) {
        hsh_insere(tab, m, n, t, e); // Usa o insere para recalcular o Hash
    }
    fclose(fp);
    return 1;
}