#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* newNode(char data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// PREORDER
void preOrder(Node* root){
    if(root != NULL){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// INORDER
void inOrder(Node* root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// POSTORDER
void postOrder(Node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {

    /*
        Tree yang dibangun:
                   R
                 /   \
                A     E
               / \
              S   T
             /
            I

        Hasil traversal:
        Pre  : R A S I T E
        In   : I S T A R E
        Post : I T S A E
    */

    Node* root = newNode('R');
    root->left = newNode('A');
    root->right = newNode('E');
    root->left->left = newNode('S');
    root->left->right = newNode('T');
    root->left->left->left = newNode('I');

    cout << "Tampilan secara PreOrder  : ";
    preOrder(root);

    cout << "\nTampilan secara InOrder   : ";
    inOrder(root);

    cout << "\nTampilan secara PostOrder : ";
    postOrder(root);

    cout << endl;
    return 0;
}
