class Solution {
#define ltr pair<int, TreeNode*>
    void _verticalOrder(TreeNode*root, int vl, map<int, vector<int>>& mp) {
        if (!root)
            return;
        _verticalOrder(root->left, vl - 1, mp);
        if (mp.find(vl) == mp.end()) {
            vector<int> *ptr = new vector<int>();
            mp[vl] = *ptr;
        }
        mp[vl].push_back(root->val);

        _verticalOrder(root->right, vl + 1, mp);
    }
    void _verticalOrderIter(TreeNode*root, int vl, map<int, vector<int>>& mp) {

        queue<ltr> q;
        if (!root)
            return;
        q.push({0, root});
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur.second->left) q.push({cur.first - 1, cur.second->left});
            if (cur.second->right) q.push({cur.first + 1, cur.second->right});
            if (mp.find(cur.first) == mp.end()) {
                vector<int> *ptr = new vector<int>();
                mp[cur.first] = *ptr;
            }
            mp[cur.first].push_back(cur.second->val);
        }
    }
    public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> map;
        vector<vector<int>> result;
        _verticalOrderIter(root, 0, map);
        for (auto e : map) {
            result.push_back(vector<int>());
            for (auto num : e.second)
                result.back().push_back(num);
        }
        return result;
    }
};
