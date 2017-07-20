class Solution {
    public:
    void _leftboundaryOfBinaryTree(TreeNode* root, bool isboundary, vector<int>& bdary) {
        if (!root)
            return;
        if (isboundary || (!root->left and !root->right)) bdary.push_back(root->val);
        _leftboundaryOfBinaryTree(root->left, isboundary, bdary);
        _leftboundaryOfBinaryTree(root->right, isboundary && !root->left, bdary);
    }
    
    void _rightboundaryOfBinaryTree(TreeNode *root, bool isboundary, vector<int>& bdary) {
        if (!root)
            return;
        _rightboundaryOfBinaryTree(root->left, isboundary && !root->right, bdary);
        _rightboundaryOfBinaryTree(root->right, isboundary, bdary);
        if (isboundary || (!root->left and !root->right))
            bdary.push_back(root->val);

    }
    public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if (root) {
                    result.push_back(root->val);
                    _leftboundaryOfBinaryTree(root->left, true, result);
                    _rightboundaryOfBinaryTree(root->right, true, result);
                }
        return result;
    }
};
