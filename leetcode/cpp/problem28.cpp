class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (!n) return 0;
        for (int i = 0; i < m - n + 1; i++) {
            int j = 0;
            for (; j < n; j++)
                if (haystack[i + j] != needle[j])
                    break;
            if (j == n) return i;
        }
        return -1;
    }
};

class Solution {
    vector<int> build_prefix(string needle) {
        vector<int> result(needle.length(), 0);
        int mIdx = 0;
        for (int i = 1; i < needle.length(); ) {
            if (needle[i] == needle[mIdx]) {
                result[i++] = ++mIdx;  
            } else {
                if (mIdx > 0)
                    mIdx = result[mIdx-1];
                else
                    result[i++] = mIdx;
            }
        }
        return result;
    }
    public:
    int strStr(string haystack, string needle) {
        vector<int> pfxtable = build_prefix(needle);
        int mIdx = 0, i = 0;
        for (; i < haystack.length() and mIdx < needle.length();) {
            if (needle[mIdx] == haystack[i]) {
                mIdx++;
                i++;
            } else {
                if (mIdx > 0)
                    mIdx = (pfxtable[mIdx - 1]);
                else
                    i++;

            }
        }
        return mIdx == needle.length() ? i - needle.length() : -1 ;
    }
};
