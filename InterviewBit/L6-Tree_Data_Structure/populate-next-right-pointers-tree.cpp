#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>


using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *A) {
  if (!A)
    return;
  queue<TreeLinkNode *> q;
  q.push(A);
  q.push(nullptr);
  TreeLinkNode *prev = nullptr;
  while (!q.empty()) {
    TreeLinkNode *node = q.front();
    q.pop();
    if (node) {
      if (node->left) {
        q.push(node->left);
        node->left->next = node->right;
      }
      if (node->right) {
        q.push(node->right);
      }
      if (prev && prev->right)
        prev->right->next = node->left;
      prev = node;
    } else {
      if (!q.empty())
        q.push(nullptr);
      prev = nullptr;
    }
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
