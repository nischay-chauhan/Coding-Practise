/* How to determine if a binary tree is height-balanced */
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

pair<int, bool> isBalancedHelper(node *root)
{
    if (root == NULL)
    {
        return {0, true};
    }

    auto leftResult = isBalancedHelper(root->left);
    auto rightResult = isBalancedHelper(root->right);

    int currentHeight = max(leftResult.first, rightResult.first) + 1;
    bool currentBalance = abs(leftResult.first - rightResult.first) <= 1 && leftResult.second && rightResult.second;

    return {currentHeight, currentBalance};
}

bool isBalanced(node *root)
{
    return isBalancedHelper(root).second;
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

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printTree(root);

    if (isBalanced(root))
    {
        cout << "Tree is Balanced" << endl;
    }
    else
    {
        cout << "Tree is not Balanced" << endl;
    }

    return 0;
}
