// proble 104. Maximum Depth of Binary Tree

class Solution {
    int maxDepthUtil(TreeNode *ptr) {
        if (ptr == nullptr)
            return 0;
        return max(maxDepthUtil(ptr->left),
                maxDepthUtil(ptr->right)) + 1;
    }
    public:
    int maxDepth(TreeNode* root) {
        return maxDepthUtil(root);

    }
};
