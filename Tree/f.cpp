/* How to determine if a binary tree is height-balanced */
#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data) {
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

int height(node* root) {
    if (root == NULL) {
        return 0;
    }

    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return max(lHeight, rHeight) + 1;
}
bool isBalanced(node* root){

    if(root == NULL){
        return true;
    }
    int lh;
    int rh;
    lh = height(root->left);
    rh = height(root->right);
    if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
        return true;
    }
    return false;
}

void printTree(node* root) {
    if (root == NULL) {
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
    if(isBalanced(root)){
        cout << "Tree is Balanced"<<endl;
    }else{
        cout << "Tree is not Balanced"<<endl;
    }
}