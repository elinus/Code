/**
 * Maximum Depth of Binary Tree
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/
 */

/**
 * Definition for a binary tree node.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (!root) return 0;
            int le = maxDepth(root->left);
            int ri = maxDepth(root->right);
            if (le > ri) {
                return le + 1;
            }
            return ri + 1;
        }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(14);
    root->right->right->right->right = new TreeNode(20);

    Solution sobj;
    std::cout << sobj.maxDepth(root) << "\n";
    return 0;
}

