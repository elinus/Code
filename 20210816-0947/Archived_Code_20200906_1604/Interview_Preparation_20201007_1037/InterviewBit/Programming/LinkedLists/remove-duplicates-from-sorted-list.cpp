 #include <bits/stdc++.h>
 
 using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
 };

 void print(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *curr = head, *prev = nullptr;
    while (curr) {
        prev = curr;
        curr = curr->next;
        while(curr != nullptr && curr->val == prev->val) {
            ListNode *temp = curr;
            curr = curr->next;
            delete temp;
        }
        prev->next = curr;
    }
    return head;
}


int main() {

}