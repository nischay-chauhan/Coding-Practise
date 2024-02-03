/* Largest value in each level of Binary Tree */
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

void preOrder(node *root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void LargestValueAtEachLevel(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int levelSize = q.size();
        int levelMax = INT_MIN;
        for(int i = 0;i<levelSize;i++){
            node* current = q.front();
            q.pop();
            levelMax = max(levelMax , current->data);
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
         cout << "Maximum value at each level is : " << levelMax << endl;
    }

}

int main(){
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right = newNode(3);
    root->right->right = newNode(20);

    printTree(root);
    cout << endl;
    LargestValueAtEachLevel(root);
    
}