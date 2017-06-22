// Class Backtracking: N-Queens problem
class Solution {
    // Generate permutation of numbers [1..N]. Check
    // whether a set is valid.
    // O(N!)
    vector<vector<string>> result;
    vector<string> generate_result(const vector<int>& sol) {
        vector<string> result;
        for (auto s : sol) {
            string row(sol.size(), '.');
            row[s-1] = 'Q';
            result.push_back(row);
        }
        return result;
    }
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
    void _solveNQueens(int npos, vector<int>&sol)
    {
        if (!isvalid(sol, npos-1)) {
            return;
        }
        if (npos == sol.size()) {
            result.push_back(generate_result(sol));
            return;
        }
        for (auto i = npos; i < sol.size(); i++) {
            swap(sol, npos, i);
            _solveNQueens(npos + 1, sol);
            swap(sol, npos, i);
        }
    }
    public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int>sol(n);
        iota(sol.begin(), sol.end(), 1);
        _solveNQueens(0, sol);
        return result;
    }
};
