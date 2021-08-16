#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode *head) {
    if (!head) return head;
    ListNode *next = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return next;
}

ListNode *reverseList(ListNode *A) {
  ListNode *curr = A, *next = nullptr, *prev = nullptr;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
