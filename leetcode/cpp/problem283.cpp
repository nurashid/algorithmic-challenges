class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int slowIt =  0, forwardIt = 0;
            while (forwardIt < nums.size()) {
                if (nums[forwardIt] != 0) {
                    nums[slowIt] = nums[forwardIt];
                    slowIt++;
                }      
                forwardIt++;
            }
            while (slowIt < nums.size())
                nums[slowIt++] = 0;
        }
};
