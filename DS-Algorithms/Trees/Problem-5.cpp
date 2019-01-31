/*
 * Inserting element into tree
 * */
#include <iostream>
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

void print(Node *root) {
    if (root) {
        std::cout << root->data << " ";
        print(root->left);
        print(root->right);
    }
}

void insert(Node *root, int key)
{
    Node *new_node = new Node(key);
    if (new_node == nullptr) {
        std::cout << "Error: out of memory" << std::endl;
        return;
    }
    if (root == nullptr) {
        root = new_node;
        return;
    }
    std::queue<Node *> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node *temp = Q.front();
        Q.pop();
        
        if (temp->left) {
            Q.push(temp->left);
        } else {
            temp->left = new_node;
            return;
        }

        if (temp->right) {
            Q.push(temp->right);
        } else {
            temp->right = new_node;
            return;
        }
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
    
    std::cout << "Print tree: ";
    print(root);
    std::cout << "\n";

    insert(root, 14);

    std::cout << "Print tree(after insert): ";
    print(root);
    std::cout << "\n";
    
    return 0;
}

