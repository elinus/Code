/*
 * Printing level order data in reverse order
 * */

#include <iostream>
#include <queue>
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

void LevelOrderInReverse(Node *root) {
    if (root) {
        std::queue<Node *> Q;
        std::stack<Node *> S;
        Q.push(root);

        while (!Q.empty()) {
            Node *temp = Q.front();
            Q.pop();
            S.push(temp);
            if (temp->right) {
                Q.push(temp->right);
            }
            if (temp->left) {
                Q.push(temp->left);
            }
        }

        while (!S.empty()) {
            std::cout << S.top()->data << " ";
            S.pop();
        }
        std::cout << "\n";
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

    LevelOrderInReverse(root);
    return 0;
}

