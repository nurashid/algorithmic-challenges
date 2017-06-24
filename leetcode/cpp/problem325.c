class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        auto answer = 0, sum = 0;
        unordered_map<int,int> hm;
        hm[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hm.find(sum - k) != hm.end())
                answer = max(answer, i - hm[sum - k]);
            if (hm.find(sum) == hm.end())
                hm[sum] = i;
        }
        return answer;      
    }
};
