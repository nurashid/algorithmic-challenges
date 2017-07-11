class Solution {
public:
    string reverseString(string s) {
        int slen = s.length() - 1;
        for (int i = 0; i < (slen + 1) / 2; i++) {
            char temp = s[i];
            s[i] = s[slen - i];
            s[slen-i] = temp;
        }
        return s;
    }
};
