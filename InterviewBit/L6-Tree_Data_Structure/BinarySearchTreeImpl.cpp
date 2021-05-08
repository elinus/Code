#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
  TreeNode *root;

public:
  BST() : root(nullptr) {}

  bool isEmpty() {
    if (!root)
      return true;
    else
      return false;
  }

  void insert(int value) {
    TreeNode *node = new TreeNode(value);
    TreeNode *parent = nullptr;
    if (isEmpty()) {
      root = node;
    } else {
      TreeNode *curr = root;
      while (curr != nullptr) {
        parent = curr;
        if (value > curr->val)
          curr = curr->right;
        else
          curr = curr->left;
      }
      if (value < parent->val)
        parent->left = node;
      else
        parent->right = node;
    }
  }

  TreeNode *insertNode(TreeNode *curr, int data) {
    if (curr == nullptr)
      return new TreeNode(data);
    if (curr->val < data)
      curr->right = insertNode(curr->right, data);
    else if (curr->val > data)
      curr->left = insertNode(curr->left, data);

    return curr;
  }

  void inOrderUtil(TreeNode *curr) {
    if (curr == nullptr)
      return;
    inOrderUtil(curr->left);
    cout << curr->val << " ";
    inOrderUtil(curr->right);
  }

  void inOrder() {
    inOrderUtil(root);
    cout << endl;
  }
};

int main(int argc, char const *argv[]) {
  BST bst;
  bst.insert(52);
  bst.insert(25);
  bst.insert(50);
  bst.insert(15);
  bst.insert(40);
  bst.insert(45);
  bst.insert(20);
  bst.inOrder();
  return 0;
}
