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
      root = parent;
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
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
