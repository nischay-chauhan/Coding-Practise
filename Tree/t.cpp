#include <iostream>
#include <algorithm>
#include <limits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 1. Maximum Path Sum in a Binary Tree
Problem: Find the maximum path sum in a binary tree where a path is defined as any sequence of nodes connected by parent-child links. The path must contain at least one node and may not pass through the root.

Approach:

Use post-order traversal to compute values bottom-up.

For each node, calculate:

The maximum path sum that can be extended upward (max_single).

The maximum path sum contained within its subtree (max_top).

Update a global maximum variable with the best path found.

 */

class SolutionPathSum {
private:
    int max_sum = std::numeric_limits<int>::min();

    int maxPathDown(TreeNode* node) {
        if (!node) return 0;

        int left_sum = std::max(0, maxPathDown(node->left));
        int right_sum = std::max(0, maxPathDown(node->right));

        max_sum = std::max(max_sum, node->val + left_sum + right_sum);

        return node->val + std::max(left_sum, right_sum);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxPathDown(root);
        return max_sum;
    }
};

// Example usage:
int main() {
    // Create a sample binary tree:
    //      -10
    //      /  \
    //     9    20
    //         /  \
    //        15   7
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    SolutionPathSum sol;
    int maxSum = sol.maxPathSum(root);

    std::cout << "Maximum path sum of the binary tree is: " << maxSum << std::endl; // Expected output: 42

    // Clean up memory
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}