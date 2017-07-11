class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(nullptr);
        
        while (q.size() > 1) {
            TreeLinkNode *cur = q.front(); q.pop();
            if (cur) {
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                cur->next = q.front();
            } else {
                q.push(cur);
            }
        }
        
        return;
    }
}
