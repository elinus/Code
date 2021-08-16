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

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    if (!A) return B;
    if (!B) return A;
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (A && B) {
        if (A->val < B->val) {
            tail->next = A;
            A = A->next;
        } else {
            tail->next = B;
            B = B->next;
        }
        tail = tail->next;
    }

    if (A) {
        tail->next = A;
    } else {
        tail->next = B;
    }
    
    return dummy.next;
}

int main(int argc, char const *argv[])
{
    ListNode *head1 = new ListNode(5);
    head1->next = new ListNode(8);
    head1->next->next = new ListNode(20);
    print(head1);
    ListNode *head2 = new ListNode(4);
    head2->next = new ListNode(11);
    head2->next->next = new ListNode(15);
    print(head2);
    print(mergeTwoLists(head1, head2));
    return 0;
}
