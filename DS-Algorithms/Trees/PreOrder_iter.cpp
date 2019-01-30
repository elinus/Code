#include <iostream>
#include <stack>

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

void preorder(Node *root) {
    std::stack<Node *> stack_;
    while (true) {
        while (root) {
            std::cout << root->data << " ";
            stack_.push(root);
            root = root->left;
        }

        if (stack_.empty()) break;
        
        root = stack_.top();
        stack_.pop();

        root = root->right;
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

    std::cout << "Preorder Traversal(iterative): ";
    preorder(root);
    std::cout << "\n";
    return 0;
}

