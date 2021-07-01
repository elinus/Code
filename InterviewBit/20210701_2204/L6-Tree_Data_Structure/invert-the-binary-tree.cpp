#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *invertTree(TreeNode *A) {
  if (A) {
    A->left = invertTree(A->left);
    A->right = invertTree(A->right);
    swap(A->left, A->right);
  }
  return A;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
