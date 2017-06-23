/*
 * 23. Merge k Sorted Lists
 *
 * Use priority queue
 * Use custom comparator
 * Default priority queue in C++ is a max_heap
 */
class Solution {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode *cur = &dummy;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (auto list : lists) {
            if (list != NULL)
                pq.push(list);
        }
        while (!pq.empty()) {
            auto node = pq.top(); pq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next != NULL) {
                pq.push(node->next);
            }
        }
        return dummy.next;

    }
};
