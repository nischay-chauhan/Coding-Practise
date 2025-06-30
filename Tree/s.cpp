#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 2. Diameter of a Binary Tree
Problem: Find the length of the longest path between any two nodes in a tree (measured by the number of edges).

Approach:

Use post-order traversal to compute subtree depths.

For each node, calculate:

Depth of left and right subtrees.

Update global diameter: left_depth + right_depth.

Return subtree depth: 1 + max(left_depth, right_depth). */

class SolutionDiameter {
    private:
        int max_diameter = 0;
        
        int depth(TreeNode* node) {
            if (!node) return 0;
            
            int left_depth = depth(node->left);
            int right_depth = depth(node->right);
            
            max_diameter = std::max(max_diameter, left_depth + right_depth);
            
            return std::max(left_depth, right_depth) + 1;
        }
    
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            depth(root);
            return max_diameter;
        }
    };

// Example usage:
int main() {
    // Create a sample binary tree:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    SolutionDiameter sol;
    int diameter = sol.diameterOfBinaryTree(root);

    std::cout << "Diameter of the binary tree is: " << diameter << std::endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}