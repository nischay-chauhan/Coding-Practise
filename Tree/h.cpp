/* A program to check if binary tree is a BST or not */
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

bool isBSTUtil(node* root, int minValue, int maxValue) {
    if (root == NULL) {
        return true;
    }

    if (root->data <= minValue || root->data >= maxValue) {
        return false;
    }

    return isBSTUtil(root->left, minValue, root->data) && isBSTUtil(root->right, root->data, maxValue);
}

bool isBST(node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(0);
    root->left->right = newNode(3);

    cout << "Binary Tree: ";
    printTree(root);

    if (isBST(root)) {
        cout << "\nIt is a Binary Search Tree (BST)." << endl;
    } else {
        cout << "\nIt is not a Binary Search Tree (BST)." << endl;
    }

    return 0;
}
