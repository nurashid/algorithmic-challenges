/*
 * 230. Kth Smallest Element in a BST
 * 
 * Just do inorder traversal and decrease k;
 */
Class Solution {
    void kthSmallestUtil(TreeNode* root, int& k, int &result) {
        if (!root || k < 0)
            return;
        kthSmallestUtil(root->left, k, result);
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        kthSmallestUtil(root->right, k, result);
           
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int result;
        kthSmallestUtil(root, k, result);
        return result;   
    }
};
