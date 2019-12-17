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
        vector<int> postorderTraversal(TreeNode* root) {
            stack<TreeNode*> s1;
            stack<TreeNode*> s2;
            vector<int> vec;
            if(root != nullptr)
                s1.push(root);
            while(!s1.empty()){
                TreeNode *node = s1.top();
                s1.pop();
                if (node->left)
                    s1.push(node->left);
                if (node->right)
                    s1.push(node ->right);
                s2.push(node);
            }
            while(!s2.empty()){
                vec.push_back(s2.top()->val);
                s2.pop();
            }

            return vec;
        }
};
