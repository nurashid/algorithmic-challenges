class Solution {
    vector<vector<int> > result;
    public:
    void swap(vector<int>& nums, int l, int r) {
        int tmp = nums[r];
        nums[r] = nums[l];
        nums[l] = tmp;
    }
    void permute(int npos, vector<int>&sol)
    {
        if (npos == sol.size()) {
            result.push_back(sol);
        } else {
            for (auto i = npos; i < sol.size(); i++) {
                swap(sol, npos, i);
                permute(npos+1, sol);
                swap(sol, npos, i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permute(0, nums);
        return result;
    }
};
