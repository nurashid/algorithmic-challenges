
class Solution {
    // O(N)
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        }
        queue<TreeNode *> myq;
        myq.push(root);
        d--;
        
        while (--d) {
            int sz = myq.size();
            for (int i = 0; i < sz; i++) {
                auto node = myq.front(); myq.pop();
                if (node->left) myq.push(node->left);
                if (node->right) myq.push(node->right);
            }
        }
        while (!myq.empty()) {
            auto n = myq.front(); myq.pop();
            auto l = new TreeNode(v);
            auto r = new TreeNode(v);
            l->left = n->left;
            r->right = n->right;
            n->left = l;
            n->right = r;
        }
        return root;
    }
};
