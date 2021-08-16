/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> vec;
            stack<TreeNode*> s;
            while(true) {
                while(root) {
                    s.push(root);
                    root = root->left;
                }
                if(s.empty()) break;
                root = s.top();
                s.pop();
                vec.push_back(root->val);
                root = root->right;
            }
            return vec;
        }
};
