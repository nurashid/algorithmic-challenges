class Solution {
    void traverse(TreeNode* root, TreeNode *&firstNode, TreeNode *&secondNode, TreeNode *&prevNode) {
        if (root == nullptr)
            return;
        traverse(root->left, firstNode, secondNode, prevNode);
        if (firstNode == nullptr and prevNode->val >= root->val)
            firstNode = prevNode;
        if (firstNode != nullptr and prevNode->val >= root->val)
            secondNode = root;
        prevNode = root;
        traverse(root->right, firstNode, secondNode, prevNode);
    }
    public:
    void recoverTree(TreeNode* root) {
        TreeNode *f = nullptr, *s = nullptr, *p = new TreeNode(INT_MIN);
        traverse(root, f, s, p);
        auto tmp = f->val;
        f->val = s->val;
        s->val = tmp;
    }  
};
