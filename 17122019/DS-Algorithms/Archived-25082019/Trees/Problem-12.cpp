/*
 * Find deepest node
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

Node *DeepestNode(Node *root) {
  if (!root) {
    return nullptr;
  }
  Node *temp = nullptr;
  std::queue<Node *> Q;
  Q.push(root);

  while (!Q.empty()) {
    temp = Q.front();
    Q.pop();

    if (temp->left) {
      Q.push(temp->left);
    }

    if (temp->right) {
      Q.push(temp->right);
    }
  }
  return temp;
}

int main(int argc, char *argv[]) {
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  Node *dn = DeepestNode(root);

  if (dn != nullptr) {
    std::cout << "Deepest node: " << dn << " : " << dn->data << "\n";
  } else {
    std::cout << "empty tree!" << std::endl;
  }

  return 0;
}
