class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        mp['0'] = 0;
        
        int res = 0;
        char prevc = 0;
        for (auto c : s) {
            
            if (mp[c] > mp[prevc]) {
                res += (mp[c] - 2*mp[prevc]);
            } else {
                res += mp[c];
            }
            prevc = c;
        } 
        return res;
    }
};
