class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (root == nullptr or root == p or root == q) return root;
            auto tleft = lowestCommonAncestor(root->left, p, q);
            auto tright = lowestCommonAncestor(root->right, p, q);
            if (tleft and tright)
                return root;
            return (tleft) ? tleft : tright;

        }
};
