Class Solution {
    // 3SUM: 1. Sort 2. Then use two pointer
    // O(N^2)
    // Runtime: 115 ms
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());     // sort the array
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) return result; // think about the corner cases
        for (int i = 0; i < n - 2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int l = i + 1, h = n-1, sum = - nums[i];
                while (l < h) {
                    if (nums[l] + nums[h] == sum) {
                        result.push_back(vector<int>{nums[i], nums[l], nums[h]});
                        while (l < h && nums[l] == nums[l+1]) l++;
                        while (l < h && nums[h] == nums[h-1]) h--;
                        l++, h--;
                    } else {
                        if (nums[l] + nums[h] < sum)
                            l++;
                        else
                            h--;
                    }
                }
            }
        }
        return result;
    }
};
