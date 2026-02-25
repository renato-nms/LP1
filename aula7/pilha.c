#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void dados_pessoa(){
    pessoa p;
    
    printf("Digite o nome");
    fgets(p.nome,100,stdin);
    getchar();
    
    printf("Digite a data de nascimento");
    scanf("%d%d%d",&p.dataNas.dia,&p.dataNas.mes,&p.dataNas.ano);
    
    printf("Digite o sexo");
    scanf("%c",p.&sexo);
}

void imprimir(Pessoa p){
    for(int i = 0; i < 100; i++){
        printf("PESSOA %d\n",i);
        printf("Nome: %s\n",&nome);
        printf("Data de nascimento: %d/%d/%d", p.data.dia, p.data.mes, p.data.ano);
        printf("Sexo: %c",&p.sexo);
    }
}

No* empilhar(No* topo){
    No* novo = (No*)malloc(sizeof(No));
    novo->p = dados_pessoa();
    novo->proximo = topo;
    return novo;
}
No* desempilhar(No* topo){
    No* novo = (No*)malloc(sizeof(No));
    No* remove;
    if(novo == NULL){
        printf("Tem nada pro beta");
    }
    topo->proximo = remove;
    remove = topo;
    
    
    
}
}