/*
Given an array of integers, return indices of the two numbers such that they
add up to a specific target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.
*/
Class Solution {
    // Just putting the numbers in HashMap and checking
    // time: O(N), space: O(N)
    // Runtime: 16 ms
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                return {map[target - nums[i]], i};
            } else {
                map[nums[i]] = i;
            }
            
        }
        return {0, 0};
    }
};
