class Solution {
    public:
    vector<int> findAnagrams(string s, string p) {
        int hmap[256] = { 0 };
        int count = 0;
        vector<int> result;
        for (auto c : p) {
            hmap[c]++;
            count++;
        }

        int left = 0, right = 0;
        while (right < count) {
            if (hmap[s[right++]]-- >= 1) count--;
            if (count == 0) result.push_back(left);
            if (right - left == p.length() and hmap[s[left++]]++ >= 0) count++;
        }
        return result;
    }
};

