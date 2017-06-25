class Solution {
    public:
    char toLower(char ch)
    {
        if (ch >= 'A' && ch <= 'Z' )
            return ch - 'A' + 'a';
        return ch;
    }

    bool isAlphaChar(char ch)
    {
        if (ch >= 'a' && ch <= 'z' )
            return true;
        if (ch >= 'A' && ch <= 'Z' )
            return true;
        if (ch >= '0' && ch <= '9' )
            return true;
        return false;
    }

    bool isPalindrome(string s) {
        if (s.empty() || s.length() == 1)
            return true;

        int st = 0, en = s.size() - 1;

        while (st < en) {
            while (!isAlphaChar(s[st]) and st < en) st++;
            while (!isAlphaChar(s[en]) and st < en) en--;
            if (st >= en)
                return true;
            if (toLower(s[st]) != toLower(s[en]))
                return false;
            st++, en--;
        }
        return true;
    }
};
