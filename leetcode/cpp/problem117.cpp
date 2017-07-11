class Solution {
    void _connect(TreeLinkNode* &pcur, TreeLinkNode* &cur, TreeLinkNode* &nlptr)
    {
        pcur->next = cur;
        pcur = pcur->next;
        if (nlptr == nullptr)
            nlptr = cur;
    }
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;
        TreeLinkNode *nLptr = root; // next level pointer
        
        while (nLptr) {
            TreeLinkNode dummy(0);
            TreeLinkNode* pcur = &dummy, *cur = nLptr;
            nLptr = nullptr;
            while (cur) {
                if (cur->left) _connect(pcur, cur->left, nLptr);
                if (cur->right) _connect(pcur, cur->right, nLptr);
                cur = cur->next;
            }
        }
        
        return;
    }
}

