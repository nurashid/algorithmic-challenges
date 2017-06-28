/*
 * 21. Merge Two Sorted Lists
 */
class Solution {
    /* Straigtforward merging */
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        
        while (l1 && l2) {
            ListNode *next;
            
            if (l1->val <= l2->val) {
                next = l1; l1 = l1->next;
            } else {
                next = l2; l2 = l2->next;
            }
            cur->next = next;
            cur = cur->next;
        }
        
        cur->next = (l1 == NULL) ? l2 : l1;
        
        return dummy.next;
        
    }
};
