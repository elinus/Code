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
        vector<int> preorderTraversal(TreeNode* root) {
            stack<TreeNode*> s;
            vector<int> vec;
            while(true){
                while(root){
                    vec.push_back(root->val);
                    s.push(root);
                    root = root->left;
                }
                if(s.empty()) break;
                root = s.top();
                s.pop();
                root = root->right;
            }
            return vec;
        }
};
