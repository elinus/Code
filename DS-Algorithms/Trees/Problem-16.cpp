/*
 * finding number of half nodes
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

int CountHalfNodes(Node *root) {
  if (!root) {
    return 0;
  }
  Node *temp = nullptr;
  std::queue<Node *> Q;
  Q.push(root);
  int half_node = 0;
  while (!Q.empty()) {
    temp = Q.front();
    Q.pop();

    if ((temp->left != nullptr && temp->right == nullptr) ||
        (temp->left == nullptr && temp->right != nullptr)) {
      half_node++;
    }

    if (temp->left) {
      Q.push(temp->left);
    }

    if (temp->right) {
      Q.push(temp->right);
    }
  }
  return half_node;
}

int main(int argc, char *argv[]) {
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  root->right->left->left = new Node(8);

  std::cout << "Count half nodes = " << CountHalfNodes(root) << "\n";

  return 0;
}
