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

ListNode* reverseList(ListNode* A, int B) {
    int count = 1;
    ListNode *curr = A, *head = nullptr, *prev = nullptr;
    while (curr)
    {
        ListNode *tmp = curr;
        while (count < B)
        {
            tmp = tmp->next;
            count++;
        }
        ListNode *next = tmp->next;
        tmp->next = nullptr;
        ListNode *rev = reverse(curr);
        if (!head) {
            head = rev;
        } else {
            prev->next = rev;
        }
        curr->next = next;
        prev = curr;
        curr = next;
        count = 1;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next = new ListNode(6);
    print(head1);
    print(reverseList(head1, 4));
    return 0;
}