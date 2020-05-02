#include <iostream>

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void inorder(TreeNode *root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(TreeNode *root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << " ";
    }
}

int main(int argc, char const *argv[]) {
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    inorder(root); 
    std::cout << "\n";
    
    preorder(root); 
    std::cout << "\n";
    
    postorder(root); 
    std::cout << "\n";

    return 0;
}

