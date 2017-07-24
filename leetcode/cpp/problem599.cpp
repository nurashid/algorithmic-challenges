class Solution {
    public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        int mi = INT_MAX;
        vector<string> result;
        for (auto i = 0; i < list1.size(); i++)
            mp[list1[i]] = i;
        for (auto i = 0; i < list2.size(); i++)
            if (mp.find(list2[i]) != mp.end()) {
                if (mi < i + mp[list2[i]]) continue;
                else if (mi > i + mp[list2[i]]) {
                    result.clear();
                }
                mi = i + mp[list2[i]];
                result.push_back(list2[i]);


            }
        return result;
    }
};
