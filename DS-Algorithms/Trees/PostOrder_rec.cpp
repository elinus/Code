#include <iostream>

/* Binary Tree Node */
struct Node {
    
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

void postorder(Node *root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << " ";
    }
}

int main (int argc, char *argv[])
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    std::cout << "Postorder Traversal: ";
    postorder(root);
    std::cout << "\n";
    return 0;
}

