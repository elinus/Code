/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* list = nullptr, *end = nullptr;

            if(l1 == nullptr && l2 == nullptr) return nullptr;
            if(l1 != nullptr && l2 == nullptr) return l1;
            if(l1 == nullptr && l2 != nullptr) return l2;

            int carry = 0, sum = 0;
            while(l1 != nullptr && l2 != nullptr) {
                sum = l1->val + l2->val + carry;
                if(sum >= 10){
                    carry = 1;
                    sum %= 10;
                } else {
                    carry = 0;
                }
                ListNode *nn = new ListNode(sum);
                if (list == nullptr) 
                    list = nn;
                else
                    end->next = nn;
                end = nn;
                l1 = l1->next;
                l2 = l2->next;
            }
            while(l1 != nullptr) {
                sum = l1->val + carry;
                if(sum >= 10){
                    carry = 1;
                    sum %= 10;
                } else {
                    carry = 0;
                }
                ListNode *nn = new ListNode(sum);
                if (list == nullptr) 
                    list = nn;
                else
                    end->next = nn;
                end = nn;
                l1 = l1->next;
            }
            while(l2 != nullptr) {
                sum = l2->val + carry;
                if(sum >= 10){
                    carry = 1;
                    sum %= 10;
                } else {
                    carry = 0;
                }
                ListNode *nn = new ListNode(sum);
                if (list == nullptr) 
                    list = nn;
                else
                    end->next = nn;
                end = nn;
                l2 = l2->next;
            }
            if(carry) {
                ListNode *nn = new ListNode(carry);
                if(list == nullptr)
                    list = nn;
                else 
                    end->next = nn;
                end = nn;
                carry = 0;
            }
            return list;

        }
};
