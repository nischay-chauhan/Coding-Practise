#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

pair<int, int> helper(TreeNode* node, int parentVal, int& maxLen) {
    if (!node) return {0, 0};
    
    auto left = helper(node->left, node->val, maxLen);
    auto right = helper(node->right, node->val, maxLen);
    
    int incr = 1, decr = 1;
    if (node->val > parentVal) {
        incr = max(left.second, right.second) + 1;
    } else if (node->val < parentVal) {
        decr = max(left.first, right.first) + 1;
    }
    
    maxLen = max({maxLen, incr, decr});
    return {incr, decr};
}

int longestAlternatingPath(TreeNode* root) {
    int maxLen = 0;
    helper(root, -1, maxLen);
    return maxLen;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode{1, nullptr, nullptr};
    root->left = new TreeNode{2, nullptr, nullptr};
    root->right = new TreeNode{3, nullptr, nullptr};
    root->left->left = new TreeNode{4, nullptr, nullptr};
    root->left->right = new TreeNode{5, nullptr, nullptr};
    root->right->right = new TreeNode{6, nullptr, nullptr};

    // Calculate the longest alternating path
    int result = longestAlternatingPath(root);
    cout << "Length of the longest alternating path: " << result << endl;

    // Clean up memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
