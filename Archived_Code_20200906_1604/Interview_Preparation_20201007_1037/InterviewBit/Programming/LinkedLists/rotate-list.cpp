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

ListNode* rotateRight(ListNode* A, int B) {
    int N = length(A);
    if (!A || !A->next || N == B) return A;
    B = N - (B %= N);
    
    ListNode *head = A, *curr = A;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = head;
    
    int count = 1;
    curr = A;
    while (count < B) {
        count++;
        curr = curr->next;
    }
    head = curr->next;
    curr->next = nullptr;
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    print(head1);
    print(rotateRight(head1, 4));
    return 0;
}