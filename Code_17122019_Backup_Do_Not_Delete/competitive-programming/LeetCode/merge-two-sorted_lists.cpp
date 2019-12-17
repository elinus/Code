#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *curr_ptr = NULL, *head_ptr = NULL;
    stack<ListNode *> st;
    while (l1 != NULL && l2 != NULL) {
      if (l1->val <= l2->val) {
        st.push(l1);
        l1 = l1->next;
      } else {
        st.push(l2);
        l2 = l2->next;
      }
    }

    while (l1 != NULL) {
      st.push(l1);
      l1 = l1->next;
    }

    while (l2 != NULL) {
      st.push(l2);
      l2 = l2->next;
    }

    while (!st.empty()) {
      curr_ptr = st.top();
      st.pop();
      // curr_ptr->next = NULL;
      if (head_ptr == NULL) {
        head_ptr = curr_ptr;
      } else {
        curr_ptr->next = head_ptr;
        head_ptr = curr_ptr;
      }
    }

    return head_ptr;
  }
};

int main(int argc, char *argv[]) {
  Solution obj;
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  ListNode *l3 = obj.mergeTwoLists(l1, l2);

  while (l3 != NULL) {
    cout << l3->val << " ";
    l3 = l3->next;
  }
  cout << "\n";

  return 0;
}
