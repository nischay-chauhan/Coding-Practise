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

void printTree(node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int height(node* root) {
    if (root == NULL) {
        return 0;
    }

    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return max(lHeight, rHeight) + 1;
}

int diameter(node* root) {
    if (root == NULL) {
        return 0;
    }

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);

    return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
}

int main() {
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->left = newNode(6);
    root->left->right = newNode(5);

    printTree(root);
    cout << endl;
    cout << "Diameter: " << diameter(root) << endl;

    return 0;
}
