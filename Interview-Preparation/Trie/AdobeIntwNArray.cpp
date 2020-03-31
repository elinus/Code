#include <iostream>
#include <vector>
#include <queue>
#include <memory>

struct TreeNode {
    int data;
    std::vector<TreeNode*> children;
    TreeNode(int data): data(data), children({})
    {}
};

class TNode {
    int value;
    public:
    std::shared_ptr<TNode> left;
    std::shared_ptr<TNode> right;
    TNode(int value): value(value)
    {}
};

void LevelOrderTraversal(TreeNode *root) {
    if (root == nullptr) return;
    std::queue<TreeNode*> qe;
    qe.push(root);
    while (!qe.empty()) {
        int n = qe.size();
        while (n) {
            TreeNode *p = qe.front();
            qe.pop();
            std::cout << p->data << " ";
            for(int i = 0; i < p->children.size(); i++) {
                qe.push(p->children[i]);
            }
            n--;
        }
    }
    std::cout << "\n";
}

void PreOrderTraversal(TreeNode *root, double prob) {
    if (!root) return;
    for (int i = 0; i < root->children.size(); i++) {
        PreOrderTraversal(root->children[i], prob/root->children.size());
    }
    if (root->children.size())
        std::cout << root->data << " " << 0 << "\n";
    else std::cout << root->data << " " << prob << "\n";
}

int main (int argc, char *argv[]) {
    TreeNode *root = new TreeNode(1);
    (root->children).push_back(new TreeNode(2));
    (root->children).push_back(new TreeNode(3));
    (root->children).push_back(new TreeNode(4));
    (root->children[0]->children).push_back(new TreeNode(5));
    (root->children[0]->children).push_back(new TreeNode(6));
    (root->children[1]->children).push_back(new TreeNode(7));
    
    LevelOrderTraversal(root);
    
    PreOrderTraversal(root, 1.0);
    std::cout << "\n";

    return 0;
}

