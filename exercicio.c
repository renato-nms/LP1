
#include <stdio.h>
#include <stdlib.h>

/* Estrutura genérica que representa um nó de uma árvore binária */
typedef struct node
{
    void *info;       // Ponteiro genérico para os dados armazenados
    struct node *lst; // Ponteiro para o filho à esquerda
    struct node *rst; // Ponteiro para o filho à direita
} Node;
//Questão 1 – tree_map
//Protótipo:

//c
void tree_map(Node *root, void (*operation)(void *));
//Descrição:
//Aplica uma operação (função callback) a todos os elementos da árvore binária genérica. O percurso deve ser em ordem (in-order traversal): subárvore esquerda, nó atual, subárvore direita.

//Parâmetros:

//root: ponteiro para o nó raiz da árvore.

//operation: função que recebe um void* (o dado armazenado no nó) e não retorna valor. Essa função será aplicada a cada elemento.

//Observação: A função não retorna nada.
void tree_map(Node* root, void (*operation)(void *)){
    if(!root){
        return;
    }
    tree_map(root->lst,operation);
     operation(root->info);
    tree_map(root->rst,operation);
   
}
//Questão 2 – tree_search
//Protótipo:

//c
Node *tree_search(Node *root, int (*condition)(void *));
//Descrição:
//Busca o primeiro nó cujo valor satisfaça uma condição definida pela função callback. O percurso deve ser em ordem (in-order traversal). 
//Retorna o ponteiro para o nó encontrado ou NULL se nenhum nó atender à condição.
//Parâmetros:

//root: ponteiro para a raiz da árvore.

//condition: função que recebe um void* e retorna um inteiro: 1 (verdadeiro) se o dado atende à condição, 0 (falso) caso contrário.

//Observação: A busca deve parar assim que o primeiro nó válido for encontrado.
Node* tree_search(Node *root, int (*condition)(void *)){
    /*
    caso base
    verifica esquerda
    verifica no atual
    verifica direita
    */
   if(!root){
    return NULL;
   }
   Node* found = tree_search(root->lst,condition);
   if(found){
    return root;
   }
   return tree_search(root->rst,condition);
}


//Questão 3 – tree_free
//Protótipo:

//c
Node *tree_free(Node *root);
//Descrição:
//Libera toda a memória ocupada pela árvore binária (nós e os dados armazenados) e retorna NULL, indicando uma árvore vazia. O percurso deve ser pós-ordem (post-order traversal): liberar subárvores primeiro, depois o nó atual.

//Parâmetros:

//root: ponteiro para a raiz da árvore.

//Retorno:
/*
NULL (a árvore resultante é vazia).

Observação:

Cada nó contém um ponteiro info que também deve ser liberado com free().

Após liberar todos os nós, a função retorna NULL.

Estrutura do nó fornecida:

*/
Node* tree_free(Node* root){
    tree_free(root->lst);
    tree_free(root->rst);
    tree_free(root->info);
    free(root);
    return NULL;
}