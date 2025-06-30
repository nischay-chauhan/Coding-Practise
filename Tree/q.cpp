/* Serialize and Deserialize a Binary Tree */

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "null";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserializeHelper(queue<string>& nodes) {
        if (nodes.empty()) return nullptr;
        
        string token = nodes.front();
        nodes.pop();
        
        if (token == "null") return nullptr;
        
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeHelper(nodes);
        node->right = deserializeHelper(nodes);
        return node;
    }

    TreeNode* deserialize(string data) {
        queue<string> nodes;
        string token;
        stringstream ss(data);
        
        while (getline(ss, token, ',')) {
            nodes.push(token);
        }
        
        return deserializeHelper(nodes);
    }
};

void printTree(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized (in-order): ";
    printTree(deserialized);
    return 0;
}