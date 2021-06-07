#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode * /*Solution::*/ mergeTwoLists(ListNode *A, ListNode *B) {
  if (!A)
    return B;
  if (!B)
    return A;

  ListNode *res = new ListNode(0);
  ListNode *tail = res;
  while (A && B) {
    if (A->val <= B->val) {
      res->next = A;
      A = A->next;
    } else {
      res->next = B;
      B = B->next;
    }
    res = res->next;
  }

  while (A) {
    res->next = A;
    res = res->next;
    A = A->next;
  }
  while (B) {
    res->next = B;
    res = res->next;
    B = B->next;
  }
  return tail->next;
}