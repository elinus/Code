/*
 * Searching an element in binary tree (iterative)
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

struct Node *search(Node *root, int key) {
  if (root == nullptr) {
    return root;
  }
  std::queue<Node *> Q;
  Q.push(root);
  while (!Q.empty()) {
    Node *temp = Q.front();
    Q.pop();
    if (temp->data == key) {
      return temp;
    }
    if (temp->left) {
      Q.push(temp->left);
    }
    if (temp->right) {
      Q.push(temp->right);
    }
  }
}

int main(int argc, char *argv[]) {
  // struct Node *root = nullptr;

  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  std::cout << "Search(5): ";
  Node *res = search(root, 5);
  if (res != nullptr) {
    std::cout << res << " : " << res->data << "\n";
  } else {
    std::cout << "Element not found!" << std::endl;
  }

  std::cout << "Search(10): ";
  res = search(root, 10);
  if (res != nullptr) {
    std::cout << res << " : " << res->data << "\n";
  } else {
    std::cout << "Element not found!" << std::endl;
  }

  return 0;
}
