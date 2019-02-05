/*
 * Finding size of binary recursively
 */

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

int SizeOfBinayTree(Node *root) {
  if (root == nullptr)
    return 0;
  else
    return SizeOfBinayTree(root->left) + 1 + SizeOfBinayTree(root->right);
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
