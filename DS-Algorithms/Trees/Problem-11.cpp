/*
 * height of tree (recursive)
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

void print(Node *root, const std::string &msg) {
  std::cout << msg << ": ";
  print_(root);
  std::cout << "\n";
}
/* Binary Tree Node }} */

int height(Node *root) {
  if (!root) {
    return 0;
  }
  int level = 0;
  std::queue<Node *> Q;
  Q.push(root);
  Q.push(nullptr);
  while (!Q.empty()) {
    Node *temp = Q.front();
    Q.pop();
    if (temp == nullptr) {
      if (!Q.empty()) {
        Q.push(nullptr);
      }
      level++;
    } else {
      if (temp->left) {
        Q.push(temp->left);
      }
      if (temp->right) {
        Q.push(temp->right);
      }
    }
  }
  return level;
}

int main(int argc, char *argv[]) {
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  std::cout << "height = " << height(root) << "\n";

  return 0;
}
