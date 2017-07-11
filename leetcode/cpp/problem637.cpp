class Solution {
    /* Quite Easy. Just travel level by level and get average */
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == nullptr) return result;
        queue<TreeNode*> myq;
        myq.push(root);
        while (!myq.empty()) {
            int sz = myq.size();
            result.push_back(0);
            for (int i = 0; i < sz; i++) {
                auto cur = myq.front(); myq.pop();
                result.back() += cur->val;
                if (cur->left) myq.push(cur->left);
                if (cur->right) myq.push(cur->right);
            }
            result.back() /= sz;
        }
        return result;
    }
};
