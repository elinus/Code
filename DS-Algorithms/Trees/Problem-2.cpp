/*
 * Find maximum in Tree
 */
#include <iostream>
#include <limits>
#include <queue>

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

int findMax(Node *root) {
    int max = std::numeric_limits<int>::min();
    std::queue<Node *> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node *temp = Q.front();
        Q.pop();
        if (temp->data > max) {
            max = temp->data;
        }
        if (temp->left) {
            Q.push(temp->left);
        }
        if (temp->right) {
            Q.push(temp->right);
        }
    }
    return max;
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

    std::cout << "Max in Tree: " << findMax(root) << "\n";
    return 0;
}

