/* Convert a Binary Tree into its Mirror Tree (invert Binary Tree) */

#include <bits/stdc++.h>
using namespace std;
class node {
    public :
    int data;
    node* left;
    node* right;
};

node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}

node* invertTree(node* root){

    if(root == NULL){
        return NULL;
    }
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left , root->right);
    return root;
}

void printTree(node* root){
    if(root == NULL){
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main(){
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printTree(root);
    cout << endl;
    invertTree(root);
    printTree(root);
    return 0;
}
