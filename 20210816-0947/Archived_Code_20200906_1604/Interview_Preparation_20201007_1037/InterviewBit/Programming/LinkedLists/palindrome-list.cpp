#include <bits/stdc++.h>

struct ListNode {
    int val;
    struct ListNode *next;
    explicit ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode* reverseList(ListNode *head) {
    ListNode *prev = nullptr, *curr = head, *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void print(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}

int lPalin(ListNode *head) {
    if (!head || !head->next) return 1;
    if (!head->next->next) {
        if (head->val != head->next->val) return 0;
        else return 1;
    }
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode *tmp = reverseList(slow->next);
    ListNode *curr = head;
    slow->next = nullptr;
    
    // print(tmp);
    // print(curr);
    
    while (curr && tmp) {
        if (curr->val != tmp->val) {
            return 0;
        }
        curr = curr->next;
        tmp = tmp->next; 
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    // print(head);
    // print(reverseList(head));
    std::cout << lPalin(head) << "\n";
    return 0;
}
