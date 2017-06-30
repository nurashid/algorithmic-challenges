class Solution {
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        vector<int> result;
        int nc = matrix[0].size(),
            nr = matrix.size();

        int l = 0, r = nc - 1, u = 0, d = nr - 1;
        while (true) {
            for (int cid = l; cid <= r; cid++)
                result.push_back(matrix[u][cid];
            if (++u > d) break;
            for (int rid = u; rid <= d; rid++)
                result.push_back(matrix[rid][r]);
            if (l > --r) break;
            for (int cid = r; cid >= l; cid--)
                result.push_back(matrix[d][cid]);
            if (u > --d) break;
            for (int rid = d; rid >= u; rid--)
                result.push_back(matrix[rid][r]);
            if (++l > r) break;
        }
        return result;
    }
};

