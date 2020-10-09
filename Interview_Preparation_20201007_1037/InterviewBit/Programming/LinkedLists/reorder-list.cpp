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
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (curr)
    {
        ListNode *new_node = new ListNode(-1);
        new_node->val = curr->val;
        tail->next = new_node;
        tail = tail->next;
        curr = curr->next;
    }
    tail->next = nullptr;
    curr = dummy.next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;   
    }
    return prev;
}


ListNode* reorderList(ListNode* head) {
    if (!head || !head->next) return head;
    int N = length(head);
    ListNode *list_rev = reverse(head);
    ListNode dummy(0);
    ListNode *tail = &dummy, *curr = head;
    int flip = 1;
    int count = 0;
    
    while (count < N) {
        ListNode *new_node = new ListNode(-1);
        if (flip) {
            new_node->val = curr->val;
            tail->next = new_node;
            tail = tail->next;
            curr = curr->next;
            flip = 0;
        } else {
            new_node->val = list_rev->val;
            tail->next = new_node;
            tail = tail->next;
            list_rev = list_rev->next;
            flip = 1;
        }
        
        count++;
    } 
    curr->next = nullptr;
    list_rev->next = nullptr;
    // print(dummy.next);
    return dummy.next;
}

int main(int argc, char const *argv[])
{
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    print(head1);
    reorderList(head1);
    return 0;
}