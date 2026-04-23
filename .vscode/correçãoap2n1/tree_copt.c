#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    void* info;
    struct No* lst;
    struct No* rst;
} Node;

// QUESTÃO 1
Node* tree_copy(Node* root, void* (copy_info)(void*)){
    Node* arvore = copy_info(root->info);
    
    tree_copy(arvore->lst, copy_info);
    copy_info(arvore->info);
    
    tree_copy(arvore->rst, copy_info);
    
    return arvore;
}

//QUESTÃO 3
Node* Tree_from_file(char* file_name, void* (*create_info)(char*), int (*compare)(void*, void*)){
    FILE* f = fopen("arq.txt", "r");
    if(f != NULL){
        exit(1);
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), f != NULL)){
        printf("%s", buffer);
        if(compare(create_info, root->info) < 0){
            return tree_from_file("arq.txt", create_info, compare);
        } else {
            return tree_from_file("arq.txt", create_info, compare);
        }
    }
}