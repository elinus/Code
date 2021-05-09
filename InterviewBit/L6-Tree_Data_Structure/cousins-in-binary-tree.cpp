#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> solve(TreeNode *A, int B) {
  queue<TreeNode *> q;
  TreeNode *curr = A;
  if (curr->val == B) {
    return vector<int>{};
  }
  q.push(curr);
  q.push(nullptr);
  bool found = false;
  while (!q.empty()) {
    while (q.front()) {
      TreeNode *front = q.front();
      q.pop();
      if (front->left && front->left->val == B) {
        found = true;
      } else if (front->right && front->right->val == B) {
        found = true;
      } else {
        q.push(front->left);
        q.push(front->right);
      }
    }
    q.pop();
    if (found == true)
      break;
    else {
      q.push(NULL);
    }
  }

  vector<int> ans;
  while (!q.empty()) {
    if (q.front() != NULL) {
      ans.push_back(q.front()->val);
    }
    q.pop();
  }
  return ans;
}

// vector<int> solve(TreeNode *A, int B) {
//   vector<int> cousins;
//   if (!A)
//     return cousins;
//   queue<pair<TreeNode *, TreeNode *>> qu;
//   qu.push({A, nullptr});
//   TreeNode *parent = nullptr;
//   vector<pair<TreeNode *, TreeNode *>> level_vec;
//   while (!qu.empty()) {
//     int size_ = qu.size();
//     while (size_) {
//       pair<TreeNode *, TreeNode *> p = qu.front();
//       qu.pop();
//       level_vec.push_back(p);
//       if (p.first->val == B) {
//         parent = p.second;
//       }
//       if (p.first->left)
//         qu.push({p.first->left, p.first});
//       if (p.first->right)
//         qu.push({p.first->right, p.first});
//       size_--;
//     }
//     if (parent) {
//       for (int i = 0; i < level_vec.size(); ++i) {
//         if (level_vec[i].second != parent)
//           cousins.push_back(level_vec[i].first->val);
//       }
//       break;
//     }
//     level_vec.clear();
//   }
//   return cousins;
// }

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
