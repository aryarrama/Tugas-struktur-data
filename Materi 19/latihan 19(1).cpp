#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef struct stree {
    char data;
    struct stree *left, *right;
} POKOK;

void BinaPokok(POKOK **akar){
    *akar = NULL;
}

int PokokKosong(POKOK *akar){
    return (akar == NULL);
}

void TambahNod(POKOK **akar, char isi){
    if (PokokKosong(*akar)) {
        *akar = (POKOK*) malloc(sizeof(POKOK));
        (*akar)->data = isi;
        (*akar)->left = (*akar)->right = NULL;
    }
}

void preOrder(POKOK *T){
    if(!PokokKosong(T)){
        printf("%c ", T->data);
        preOrder(T->left);
        preOrder(T->right);
    }
}

void inOrder(POKOK *T){
    if(!PokokKosong(T)){
        inOrder(T->left);
        printf("%c ", T->data);
        inOrder(T->right);
    }
}

void postOrder(POKOK *T){
    if(!PokokKosong(T)){
        postOrder(T->left);
        postOrder(T->right);
        printf("%c ", T->data);
    }
}

int main(){
    POKOK *akar;

    BinaPokok(&akar);

    TambahNod(&akar, 'R');             
    TambahNod(&akar->left, 'A');      
    TambahNod(&akar->right, 'E');     
    TambahNod(&akar->left->left, 'S'); 
    TambahNod(&akar->left->left->left, 'I'); 
    TambahNod(&akar->left->left->right, 'T'); 

    printf("Tampilan secara PreOrder  : ");
    preOrder(akar);

    printf("\nTampilan secara InOrder   : ");
    inOrder(akar);

    printf("\nTampilan secara PostOrder : ");
    postOrder(akar);

    return 0;
}