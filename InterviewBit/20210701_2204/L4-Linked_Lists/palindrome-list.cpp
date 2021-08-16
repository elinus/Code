#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head) {
  ListNode *curr = head, *prev = nullptr, *next = nullptr;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

bool check(ListNode *l1, ListNode *l2) {
  while (l1 && l2) {
    if (l1->val != l2->val)
      return false;
    l1 = l1->next;
    l2 = l2->next;
  }
  return true;
}

int lPalin(ListNode *A) {
  if (!A)
    return true;
  ListNode *slow = A, *fast = A;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *l1 = A;
  ListNode *l2 = reverse(slow->next);
  slow->next = nullptr;
  return check(l1, l2);
}