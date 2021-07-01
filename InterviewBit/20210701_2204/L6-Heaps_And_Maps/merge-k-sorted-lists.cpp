#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &A) {
  if (A.empty())
    return nullptr;
  int n = A.size();
  ListNode dummy(0);
  ListNode *tail = &dummy;
  while (true) {
    int min_idx = -1, min_elem = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (!A[i])
        continue;
      if (A[i] && A[i]->val < min_elem) {
        min_elem = A[i]->val;
        min_idx = i;
      }
    }
    if (min_elem == INT_MAX)
      break;
    tail->next = A[min_idx];
    tail = tail->next;
    A[min_idx] = A[min_idx]->next;
  }
  return dummy.next;
}

class Solution {
public:
  struct CompareNode {
    bool operator()(ListNode *const &p1, ListNode *const &p2) {
      // return "true" if "p1" is ordered before "p2", for example:
      return p1->val > p2->val;
    }
  };
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    priority_queue<ListNode *, vector<ListNode *>, CompareNode> queue;

    for (int i = 0; i < lists.size(); i++) {
      if (lists[i] != NULL) {
        queue.push(lists[i]);
      }
    }

    while (!queue.empty()) {
      tail->next = queue.top();
      queue.pop();
      tail = tail->next;

      if (tail->next) {
        queue.push(tail->next);
      }
    }

    return dummy->next;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
