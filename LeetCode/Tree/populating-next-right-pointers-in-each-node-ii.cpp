
#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (!root)
      return root;
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    vector<Node *> nodes;
    while (!q.empty()) {
      Node *node = q.front();
      q.pop();
      if (node) {
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
        nodes.push_back(node);
      } else {
        if (!q.empty())
          q.push(nullptr);
        for (int i = 0; i < nodes.size() - 1; ++i) {
          nodes[i]->next = nodes[i + 1];
        }
        nodes.clear();
      }
    }
    return root;
  }
};