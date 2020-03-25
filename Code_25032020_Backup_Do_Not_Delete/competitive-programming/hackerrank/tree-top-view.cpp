#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

                return root;
            }
        }

        struct NodeIndexPair {
            Node *node;
            int index;
        };
        
        void viewUtil(Node *root, map<int, int> & mh, int index) {
            if (root) { 
                queue<NodeIndexPair> q;
                q.push({root, index});
                while (!q.empty()) {
                    NodeIndexPair nip = q.front();
                    q.pop();
                    if (mh.find(nip.index) == mh.end()) {
                        mh[nip.index] = (nip.node)->data;
                    }
                    if ((nip.node)->left != nullptr) {
                        q.push({(nip.node)->left, nip.index - 1});
                    }
                    if ((nip.node)->right != nullptr) {
                        q.push({(nip.node)->right, nip.index + 1});
                    }
                }
            }

        }

        void topView(Node * root) {
            if (root == nullptr) return;
            map<int, int> mh;
            viewUtil(root, mh, 0);
            for(auto it = mh.begin(); it != mh.end(); it++) {
                std::cout << it->second << " ";
            }
            std::cout << "\n";
        }

}; //End of Solution

int main (int argc, char *argv[]) {
    Node *root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(6);
    root->right->right->left->right = new Node(4);
    Solution sObj;
    sObj.topView(root);

	Node *root1 = new Node(1);
	root1->left = new Node(2);
	root1->left->left = new Node(4);
	root1->left->right = new Node(5);
	root1->right = new Node(3);
	root1->right->left = new Node(6);
	root1->right->right = new Node(7);
    sObj.topView(root1);
    
    Node *root2 = new Node(1);
    sObj.topView(root2);
	
    Node *root3 = new Node(1);
	root3->left = new Node(2);
	root3->left->left = new Node(4);
	root3->left->right = new Node(5);
	root3->left->right->right = new Node(6);
	root3->left->right->right->right = new Node(7);
	root3->right = new Node(3);
    sObj.topView(root3);
    
    return 0;
}

