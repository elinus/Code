struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode * /*Solution::*/ detectCycle(ListNode *A) {
  if (!A || !A->next)
    return nullptr;

  ListNode *slow, *fast;
  slow = fast = A;
  while (fast) {
    if (!fast->next || !fast->next->next)
      return nullptr;
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      break;
  }
  slow = A;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}