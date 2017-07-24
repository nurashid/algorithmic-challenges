class Solution {
    public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL || root->left == NULL)
            return root;
        
        TreeNode *tmp = upsideDownBinaryTree(root->left);
        root->left->left = root->right;
        root->left->right = root;
        root->left = root->right = NULL;
        return tmp;
        
    }
};
