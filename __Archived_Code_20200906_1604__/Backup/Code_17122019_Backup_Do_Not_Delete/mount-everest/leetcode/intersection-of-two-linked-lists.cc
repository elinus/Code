#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            int len_a = 0, len_b = 0;
            ListNode *currA = nullptr, currB = nullptr;
            while (currA)
            {
                len_a++;
                currA = currA->next;
            }
            while (currB) 
            {
                len_b++;
                currB = currB->next;
            }
            int diff;
            if (len_a >= len_b) 
            {
                diff = len_a - len_b;
                currA = headA;
                currB = headB;
                while (diff-- > 0) currA = currA->next;
                while(!currB || !currA)
                {
                    if (currA == currB)
                    {
                        return currA;
                    }
                    else 
                    {
                        currA = currA->next;
                        currB = currB->next;
                    }
                }
            } 
            else 
            {
                diff = len_b - len_a;
                currB = headB;
                while (diff-- > 0) currB = currB->next;
                while(!currB || !currA)
                {
                    if (currA == currB)
                    {
                        return currA;
                    }
                    else 
                    {
                        currA = currA->next;
                        currB = currB->next;
                    }
                }
            }
            return nullptr;
        }
};

int main (int argc, char *argv[]) 
{
    
    return 0;
}

