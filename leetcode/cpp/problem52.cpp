class Solution {
    vector<vector<string>> result;
    int cnt;
    void swap(vector<int>& arr, int i, int j) {
        auto tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    bool isvalid(const vector<int>&sol, int npos) {
        bool res = true;
        for (int i = npos - 1; i >= 0; i--) {
            if (abs(sol[i] - sol[npos]) == npos - i) {
                res = false;
                break;
            }
        }
        return res;
    }
    void _totalNQueens(int npos, vector<int>&sol)
    {
        if (!isvalid(sol, npos-1)) {
            return;
        }
        if (npos == sol.size()) {
            cnt++;
            return;
        }
        for (auto i = npos; i < sol.size(); i++) {
            swap(sol, npos, i);
            _totalNQueens(npos + 1, sol);
            swap(sol, npos, i);
        }
    }
    public:
    int totalNQueens(int n) {
        vector<int>sol(n);
        cnt = 0;
        iota(sol.begin(), sol.end(), 1);
        _totalNQueens(0, sol);
        return cnt;
    }
};
