/* Find Count of Single Valued Subtrees  */ 
/* Given a binary tree, write a program to count the number of Single Valued Subtrees. A Single Valued Subtree is one in which all the nodes have same value. Expected time complexity is O(n).

Example: 

Input: root of below tree
              5
             / \
            1   5
           / \   \
          5   5   5
Output: 4
There are 4 subtrees with single values.
Input: root of below tree
              5
             / \
            4   5
           / \   \
          4   4   5                
Output: 5
There are five subtrees with single values. */

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

int countSingleValuedSubtrees(node *root , int &count){
    if(root == NULL)
        return true;

    bool left = countSingleValuedSubtrees(root->left , count);
    bool right = countSingleValuedSubtrees(root->right , count);

    if(left && right){
        if(root->left  && root->data != root->left->data)
            return false;
        if(root->right && root->data != root->right->data)
            return false;
        count++;
        return true;
    }
    return false;
}

int countSingleValuedSubtrees(node *root){
    int count = 0;
    countSingleValuedSubtrees(root , count);
    return count;
}

int main(){
    node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(5);
    root->left->left = newNode(5);
    root->left->right = newNode(5);
    root->right->right = newNode(5);
    printTree(root);
    cout << endl;
    cout << countSingleValuedSubtrees(root);
}