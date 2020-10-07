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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> vov;
            stack<TreeNode*> s1;
            stack<TreeNode*> s2;
            if(root != nullptr)
                s1.emplace(root);
            while(!s1.empty() || !s2.empty()){
                vector<int> v1;
                while(!s1.empty()){
                    TreeNode *node = s1.top();
                    s1.pop();
                    v1.emplace_back(node->val);
                    if(node->left)
                        s2.push(node->left);
                    if(node->right)
                        s2.push(node->right);
                }
                if(!v1.empty())
                    vov.emplace_back(v1);

                vector<int> v2;
                while(!s2.empty()){
                    TreeNode *node = s2.top();
                    s2.pop();
                    v2.emplace_back(node->val);
                    if(node->right)
                        s1.push(node->right);
                    if(node->left)
                        s1.push(node->left);
                }
                if(!v2.empty())
                    vov.emplace_back(v2);
            }
            return vov;
        }
};
