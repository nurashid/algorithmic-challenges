/*
 * 237. Delete Node in a Linked List
 *
 * Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node.
 *
 * Algo is pretty simple
 * 1. copy contents of next node to the current one
 * 2. delete the next node 
 */
class Solution {
    public:
    void deleteNode(ListNode* node) {
            node->val = node->next->val;
            node->next = node->next->next;
        }
};
