class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0], curr_max = nums[0];
        int size = nums.size();

        for (int i = 1; i < size; i++)
        {
            /* This line is very important. curr_max is the 
             * prefix here. If the prefix value + current number
             * is smaller than current number, then
             * choose current number 
             */
            curr_max = max(nums[i], curr_max+nums[i]);
            max_so_far = max(max_so_far, curr_max);
        }
        return max_so_far;

    }
};
