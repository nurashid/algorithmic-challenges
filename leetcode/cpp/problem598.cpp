class Solution {
    public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int _m = INT_MAX, _n = INT_MAX;
        for (auto op : ops) {
            _m = min(_m, op[0]);
            _n = min(_n, op[1]);
        }
        return ops.size() > 0 ? _m*_n : m*n;
    }
};

class Solution {
    public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m*n;
    }
};

