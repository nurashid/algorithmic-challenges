class Solution {
    void _reverseWords(string& st, size_t s, size_t e) {
        while (s < e) {
            char t = st[s];
            st[s] = st[e];
            st[e] = t;
            s++, e--;
        }
    }
public:
    string reverseWords(string str) {
        size_t bInd = 0;

        while (1) {
            bInd = str.find_first_not_of(" ", bInd);
            auto eInd = str.find_first_of(" ", bInd);
            eInd = (eInd == string::npos) ? str.length() : eInd;
            _reverseWords(str, bInd, eInd-1);
            if (eInd == str.length()) break;
            bInd = eInd;
        }
        return str;
    }
};
