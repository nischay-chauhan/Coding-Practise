/* Symmetric Tree (Mirro Image of Itself) */

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
void printTree(node* root){
    if(root == NULL){
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

bool isMirror(node* root1 , node* root2){
    if(root1 == NULL && root2 == NULL)
        return true;
    
    if(root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left , root2->right) && isMirror(root1->right , root2->left);
    
    return false;
}

int main(){ 
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
    printTree(root);
    if(isMirror(root , root)){
        cout << "Tree is Symmetric"<<endl;
    }else{
        cout << "Tree is not Symmetric"<<endl;
    }
    return 0;
}   