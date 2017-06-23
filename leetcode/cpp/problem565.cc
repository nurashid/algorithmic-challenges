/*
 * 565. Array Nesting
 * Simple caching
 * O(N)
 */
class Solution {
    int* ptr;
    int arrayNestingUtil(const vector<int>& nums, int ind) {
        if (ptr[ind] > 0)
            return ptr[ind];
        if (ptr[ind] == 0)
            return 0;
        ptr[ind] = 0;
        ptr[ind] = 1 + arrayNestingUtil(nums, nums[ind]);
        return ptr[ind];
    }
public:
    int arrayNesting(vector<int>& nums) {
        int gmax = 0;
        ptr = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) ptr[i] = -1;
        
        for (int i = 0; i < nums.size(); i++)
            gmax = max(gmax, arrayNestingUtil(nums, i));
        return gmax;
        
    }
};
