class Solution {
    public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        auto m1 = nums[l-1]*nums[l-2]*nums[l-3],
             m2 = nums[0]*nums[1]*nums[l-1];
        return max(m1, m2);
    }
};
