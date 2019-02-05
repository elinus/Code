/*
 * Searching an element in binary tree (recursive)
 * */

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

struct Node *search(Node *root, int key) {
  if (root == nullptr || root->data == key) {
    return root;
  } else {
    Node *temp = search(root->left, key);
    if (temp != nullptr) {
      return temp;
    } else {
      return search(root->right, key);
    }
  }
}

int main(int argc, char *argv[]) {
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
