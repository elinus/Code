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

int listLength(ListNode *head) {
    int count = 0;
    ListNode *curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

ListNode* removeNthFromEnd(ListNode* A, int B) {
    if (!A) return A;
    int N = listLength(A);
    if (B >= N) {
        ListNode *tmp = A;
        A = A->next;
        delete tmp;
        return A;
    } 
    ListNode *curr = A, *prev = nullptr;
    int count = 1;
    while (count < (N - B + 1)) {
        prev = curr;
        curr = curr->next;
        count++;
    }
    if (curr->next == nullptr) prev->next = nullptr;
    else {
        prev->next = curr->next;
    }
    if (!curr) delete curr;
    return A;
}

int main(int argc, char const *argv[])
{
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    print(head1);
    
    print(removeNthFromEnd(head1, 5));
    return 0;
}