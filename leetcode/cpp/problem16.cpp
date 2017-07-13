Class Solution {
    // 3SUM Closest: 1. Sort 2. Then use two pointer
    // O(N^2)
    // Runtime: 115 ms
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());     // sort the array
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) return result; // think about the corner cases
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, h = n-1;
            while (l < h) {
                auto sum = nums[l] + nums[h] + nums[i];
                if (sum == target)
                    return target;
                if (abs(sum) < abs(m))
                    m = sum;
                if (s < 0)
                    l++;
                else
                    h--;
            }
        }
        return m;
    }
};
