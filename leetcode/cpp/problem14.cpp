class Solution {
    // For first string, scan all other string. If you don't
    // find a match return;
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.size() == 0)
            return result;
        int i = 0;
        for (; i < strs[0].length(); i++) {
            for (auto str : strs) {
                if (i == str.length() || strs[0][i] != str[i])
                    return result;
            }   
            result += strs[0][i];
        }
        return result;
    }
};
