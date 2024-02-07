/* Print the Left view of a Binary Tree */
#include<bits/stdc++.h>
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

void leftViewTree(node* root){
    if(root == NULL){
        return;
    }
    
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        int n = q.size();
        
        for(int i=1; i<=n; i++){
            node* temp = q.front();
            q.pop();
            
            if(i==1){ 
                cout << temp->data << " ";
            }
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printTree(root);
    cout << endl;
    leftViewTree(root);
}