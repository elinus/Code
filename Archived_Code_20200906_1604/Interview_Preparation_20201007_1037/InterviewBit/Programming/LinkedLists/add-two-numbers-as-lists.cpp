#include <bits/stdc++.h>

struct ListNode {
    int val;
    struct ListNode *next;
    explicit ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

void print(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}

int length(ListNode *head) {
    int count = 0;
    ListNode *curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

ListNode* reverse(ListNode *head) {
    ListNode *curr = head, *prev = nullptr, *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;   
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return nullptr;
        if (!l1) return l2;    
        if (!l2) return l1;    
        if (l1->val == 0 && !l1->next) return l2;
        if (l2->val == 0 && !l2->next) return l1;
        
        ListNode *dummy = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = dummy;
        int carry = 0;
        while (p || q) {
            int sum = carry + (p ? p->val : 0) + (q ? q->val : 0);
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p) p = p->next;
            if (q) q = q->next;
        }
        if (carry) curr->next = new ListNode(carry);
        return dummy->next;
}

int main(int argc, char const *argv[])
{
    ListNode *head1 = new ListNode(9);
    head1->next = new ListNode(9);
    head1->next->next = new ListNode(1);
    // head1->next->next->next = new ListNode(4);
    // head1->next->next->next->next = new ListNode(5);
    print(head1);
    ListNode *head2 = new ListNode(1);
    // head2->next = new ListNode(6);
    // head2->next->next = new ListNode(4);
    // head2->next->next->next = new ListNode(4);
    // head2->next->next->next->next = new ListNode(5);
    print(head2);
    print(addTwoNumbers(head1, head2));
    return 0;
}