/* Check for Children Sum property in a Binary Tree */
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

void printTree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

bool isSumTree(node* root){
    int sum = 0;
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return true;
    }
    if(root->left != NULL){
        sum += root->left->data;
    }
    if(root->right != NULL){
        sum += root->right->data;
    }
    if(root->data == sum && isSumTree(root->left) && isSumTree(root->right)){
        return true;
    }
    return false;
}

int main(){

    node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(2);
    printTree(root);
    cout << endl;
    if(isSumTree(root)){
        cout << "Tree is Sum Tree" << endl;
    }else{
        cout << "Tree is not Sum Tree" << endl;
    }
    return 0;
}