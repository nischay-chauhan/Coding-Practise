/** Find the maximum Depth and Height of the given binary Tree */

#include <bits/stdc++.h>
using namespace std;

class node {
    public :
    int data;
    node* left;
    node* right;
};

int maxDepth(node* root){
    if(root == NULL){
        return 0;
    }else{
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        if(lDepth > rDepth){
            return lDepth + 1;
        }else{
            return rDepth + 1;
        }
    }
}

node* newNode(int data){
    node* n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(){
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout <<"Height of Tree is " << maxDepth(root);
    return 0;
}

// Time complexity : O(n)