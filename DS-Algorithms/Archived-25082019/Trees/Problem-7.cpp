/*
 * Finding size of binary iterative
 */

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

int SizeOfBinayTree(Node *root) {
  if (root == nullptr) {
    return 0;
  }
  std::queue<Node *> Q;
  Q.push(root);
  int count = 0;
  while (!Q.empty()) {
    Node *temp = Q.front();
    Q.pop();
    count++;
    if (temp->left) {
      Q.push(temp->left);
    }
    if (temp->right) {
      Q.push(temp->right);
    }
  }
  return count;
}

int main(int argc, char *argv[]) {
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  std::cout << "Size of Binary Tree: " << SizeOfBinayTree(root) << "\n";

  return 0;
}
