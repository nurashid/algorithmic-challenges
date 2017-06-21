/*
Given an array consists of non-negative integers, your task is to count the
number of triplets chosen from the array that can make triangles if we take
them as side lengths of a triangle.
*/
Class Solution {
public:
    // O(N^2)
    // Runtime: 12 ms
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto res = 0;
        for (int i = nums.size() - 1; i >= 2; i--) {
            auto l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    res += (r - l);
                    r--;
                } else {
                    l++;
                }
            }
        }
        return res;
    }
};
