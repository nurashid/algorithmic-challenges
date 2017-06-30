/* Just scan from left and right
 * Two-pointer method
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>res(size, 1);
        int l = 1, r = 1;
        for (int i = 0; i < size; i++) {
            res[i] *= l;
            l *= nums[i];
            res[size-1-i] *= r;
            r *= nums[size-1-i];
        }
        return res;
    }
};
