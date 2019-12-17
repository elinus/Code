/*
 * Find maximum in Tree (recursive)
 */
#include <iostream>
#include <limits>

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
  if (root == nullptr) {
    return std::numeric_limits<int>::min();
  }
  int res = root->data;
  int left_ = findMax(root->left);
  int right_ = findMax(root->right);
  if (left_ > res) {
    res = left_;
  }
  if (right_ > res) {
    res = right_;
  }
  return res;
}

int main(int argc, char *argv[]) {
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
