/* 1. Maximum Path Sum in a Binary Tree
Problem: Find the maximum path sum in a binary tree where a path is defined as any sequence of nodes connected by parent-child links. The path must contain at least one node and may not pass through the root.

Approach:

Use post-order traversal to compute values bottom-up.

For each node, calculate:

The maximum path sum that can be extended upward (max_single).

The maximum path sum contained within its subtree (max_top).

Update a global maximum variable with the best path found. */

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int max_sum = INT_MIN;
    
    int maxPathDown(TreeNode* node) {
        if (!node) return 0;
        
        int left_sum = max(0, maxPathDown(node->left));
        int right_sum = max(0, maxPathDown(node->right));
        
        max_sum = max(max_sum, left_sum + right_sum + node->val);
        
        return max(left_sum, right_sum) + node->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        maxPathDown(root);
        return max_sum;
    }
};

int main() {
    // Example tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;
    int result = solution.maxPathSum(root);
    cout << "Maximum path sum: " << result << endl;

    // Clean up memory (optional)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
