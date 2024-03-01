/* Vertical order traversal of Binary Tree using Map 
      Input:         1
                  /    \ 
                2      3
               / \   /   \
             4    5  6   7
                        /  \ 
                       8    9 

Output: 

4
2
1 5 6
3 8
7
9
*/

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
    if(root == NULL) {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

void getVerticalOrder(node* root, int hd, map<int, vector<int>>& m) {
    if (root == NULL) {
        return;
    }

    m[hd].push_back(root->data);

    getVerticalOrder(root->left, hd - 1, m);
    getVerticalOrder(root->right, hd + 1, m);
}

void printVertical(node* root) {
    map<int, vector<int>> m;
    int hd = 0;
    getVerticalOrder(root, hd, m);

    for (auto it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < it->second.size(); ++i) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);
    root->right->right->right = newNode(9);

    cout << "Vertical order traversal is \n";
    printVertical(root);
    return 0;
}
