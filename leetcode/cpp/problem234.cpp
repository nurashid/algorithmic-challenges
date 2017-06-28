class Solution {
public:
    ListNode* reversetList(ListNode* st, ListNode *en) {
        ListNode dummy(0),
                 *cur = st;
        ListNode *reversedsofar = nullptr;
        while (cur != en) {
            ListNode *tmp = cur->next;
            cur->next = reversedsofar;
            reversedsofar = cur;
            cur = tmp;
        }
        return reversedsofar;
    }
    void printList(ListNode * head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    bool isPalindrome(ListNode* head) {
        ListNode * sl = head,
                 * fs = head;
        while (fs and fs->next) {
            sl = sl->next;
            fs = fs->next->next;
        }
        ListNode *rhalf = reversetList(head, sl);
        if (fs) sl = sl->next;
        while (rhalf) {
            if (rhalf->val != sl->val)
                return false;
            rhalf = rhalf->next;
            sl = sl->next;
        }
        return true;
    }
};
