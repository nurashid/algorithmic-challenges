/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 1 2 3
// s
//   f
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr)
            return new TreeNode(head->val);
        ListNode * sl = head,
                 * fs = head->next;
        while (fs and fs->next) {
            sl = sl->next;
            fs = fs->next->next;
        }     
        ListNode *rList = sl->next->next;
        TreeNode *root = new TreeNode(sl->next->val);
        sl->next = nullptr;
        root->right = sortedListToBST(rList);
        root->left = sortedListToBST(head);
        return head;
    }
};
