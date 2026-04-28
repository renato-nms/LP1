#include <stdio.h>
#include <stdlib.h>

#define TAM 31

void inicializaTabel(int t[]){
    int i;
    for(i = 0; i < TAM; i++){
        t[i] = -1; 
    }
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserirHash(int t[], int valor){
    int id = funcaoHash(valor);
    while(t[id] != -1){
        t[id] = funcaoHash(id+1);
    }
    t[id] = valor;
}

int main (void) {

    return 0;
}