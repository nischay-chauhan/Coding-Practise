/* Program to determine if given two trees are identical or not */

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
 
int identicalTrees(node* a ,  node*b){
    if(a == NULL && b == NULL){
        return 1;
    }
    if(a != NULL && b != NULL){
        return (a->data == b->data && identicalTrees(a->left , b->left) && identicalTrees(a->right , b->right));
    }
    return 0;
}

int main(){
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    if(identicalTrees(root , root2)){
        cout << "Trees are identical"<<endl;
    }else{
        cout << "Trees are not identical"<<endl;
    }
    return 0;
}