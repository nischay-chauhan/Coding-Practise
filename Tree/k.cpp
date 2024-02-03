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

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void zigzagTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    deque<node *> dq;
    dq.push_back(root);
    bool leftToRight = true;

    while (!dq.empty())
    {
        int levelSize = dq.size();

        for (int i = 0; i < levelSize; ++i)
        {
            if (leftToRight)
            {
                node *current = dq.front();
                dq.pop_front();
                cout << current->data << " ";

                if (current->left)
                {
                    dq.push_back(current->left);
                }

                if (current->right)
                {
                    dq.push_back(current->right);
                }
            }
            else
            {
                node *current = dq.back();
                dq.pop_back();
                cout << current->data << " ";

                if (current->right)
                {
                    dq.push_front(current->right);
                }

                if (current->left)
                {
                    dq.push_front(current->left);
                }
            }
        }

        leftToRight = !leftToRight;
    }
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "ZigZag Traversal: ";
    zigzagTraversal(root);
    cout << endl;

    return 0;
}
