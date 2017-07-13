class Solution {
    public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> dp(nums);
        for (auto i = 1; i < nums.size(); i++)
            dp[i] = max(dp[i-1], nums[i] + ((i >= 2) ? dp[i-2] : 0));
        return dp.back();
    }
};
