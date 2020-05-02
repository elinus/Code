/*
 * Deleting Tree
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

void print_(Node *root) {
  if (root) {
    std::cout << root->data << " ";
    print_(root->left);
    print_(root->right);
  }
}

void print(Node *root, const std::string &msg) {
  std::cout << msg << ": ";
  print_(root);
  std::cout << "\n";
}

void Delete(Node *root) {
  if (!root) {
    return;
  }
  Delete(root->left);
  Delete(root->right);
  delete root;
}

int main(int argc, char *argv[]) {
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  print(root, "Before deleteing");
  Delete(root);
  print(root, "After deleteing");
  return 0;
}
