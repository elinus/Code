/*
 * deleting node
 * */
#include <iostream>
#include <queue>

/* {{ Binary Tree Node */
struct Node {
    
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

void print_(Node *root) {
    if (root) {
        std::cout << root->data << " ";
        print_(root->left);
        print_(root->right);
    }
}

void print(Node *root,  const std::string &msg) {
    std::cout << msg << ": ";
    print_(root);
    std::cout << "\n";
}
/* Binary Tree Node }} */

void DeleteNode(Node *root, int key) {
    if (!root) {
        std::cout << "Error: empty tree!" << std::endl;
        return;
    }
    Node *temp = nullptr, *temp_ = nullptr;
    std::queue<Node*> Q;
    Q.push(root);
    
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();

        if (temp->data == key) {
            temp_ = temp;
        }
        
        if (temp->left) {
            Q.push(temp->left);
        }

        if (temp->right) {
            Q.push(temp->right);
        }
    }

    if (temp_ != nullptr) {
        temp_->data = temp->data;
        delete temp;
    } else {
        std::cout << "elem not present!" << std::endl;
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
   
    print(root, "Before deleting 3: ");
    DeleteNode(root, 3);
    print(root, "After deleting 3: ");
    
    return 0;
}

