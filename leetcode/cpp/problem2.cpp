/*
You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order and each of their nodes contain
a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // General method of summing. function call adds overhead.
    // Runtime: 49 ms
    int getValAndUpdate(ListNode *&cur) {
        auto a = 0;
        if (!cur) {
            a = cur->val; 
            cur = cur->next;
        }
        return a;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        
        ListNode dummy(0);
        ListNode *ptr = &dummy;
        
        while (cur1 || cur2) {
            auto a = getValAndUpdate(cur1),
                 b = getValAndUpdate(cur2);

            auto sum = a + b + carry;
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            carry = sum/10;
           
        }
        if (carry)
            ptr->next = new ListNode(carry);
        return dummy.next;
    }
};
