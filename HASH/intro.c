#include <stdio.h>

##define TAM 31

void inicializa(int t[]{
    int i;
    for(i = 0; i< TAM; i++){
        t[0] = 0;
    }
})

int funcaoHASH(int chave){
    return chave % TAM;
}

void insere(int valor){
    int id = funcaoHASH;

    while(t[id]!= 0){
        t[id] = funcaoHASH(id + 1);
    }
    t[id] = valor;
}

int busca(int t[],int chave){
    int id = funcaoHASH(chave);

    while(t[id] != 0){
        if(t[id] == chave)
        return t[id];
        else
        t[id] = funcaoHASH(id+1);
    }
    return -1;
}

