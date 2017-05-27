
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

int isInterleave(char* s1, char* s2, char* s3) {
    if (*s1 == 0 and *s2 == 0 and *s3 == 0)
        return true;
    if (*s3 != 0) {
        if (*s1 != 0 and *s1 == *s3
            and isInterleave(s1+1, s2, s3+1))
                return true;
        if (*s2 != 0 and *s2 == *s3
            and isInterleave(s1, s2+1, s3+1))
                return true;
    }
    return false;
}

class Solution {
#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>
#define vi vector<int>
    int isInterleaveUtil(string s1, string s2, string s3,
                          int i, int j, int k) {
        if (i == s1.length() and j == s2.length() and
                k == s3.length())
            return 1;
        if (k != s3.length()) {
            if (i != s1.length() and s1[i] == s3[k]
                   and isInterleaveUtil(s1, s2, s3, i+1, j, k+1))
                return 1;
            if (j != s2.length() and s2[j] == s3[k]
                   and isInterleaveUtil(s1, s2, s3, i, j+1, k+1))
                return 1;
         }


        return 0;
    }
    int isInterleaveUtil(string s1, string s2, string s3,
            int i, int j, int k, vvvi& dp) {
        if (i > s1.length() || j > s2.length() || k > s3.length())
            return 0;
        if (dp[i][j][k] == -1) {
            if (i == s1.length() and j == s2.length() and
                    k == s3.length()) {
                dp[i][j][k] = 1;
                return 1;
            }
            if (k != s3.length()) {
                if (i != s1.length() and s1[i] == s3[k]
                        and isInterleaveUtil(s1, s2, s3, i+1, j, k+1, dp)) {
                    dp[i][j][k] = 1;
                    return 1;
                }
                if (j != s2.length() and s2[j] == s3[k]
                        and isInterleaveUtil(s1, s2, s3, i, j+1, k+1, dp)) {
                    dp[i][j][k] = 1;
                    return 1;
                }
            }

        } else {
            return dp[i][j][k];
        }
        dp[i][j][k] = 0;
        return 0;
    }
    public:
    int isInterleave(string s1, string s2, string s3) {
        vvvi dp(s1.length() + 1, vvi(s2.length() + 1, vi(s3.length() + 1, -1)));

        isInterleaveUtil(s1, s2, s3, 0, 0, 0, dp);
        return dp[s1.length()][s2.length()][s3.length()];
    }
};

int main() {
    char bmd[] = "aabcc";
    char cmd[] = "dbbca";
    char intr[] = "aadbbcbcac";
    char intt[] = "aadbbbaccc";
    Solution s;
    //cout << isInterleave((char *)&bmd, (char *)&cmd, (char *)&intr) << endl;
    //cout << isInterleave((char *)&bmd, (char *)&cmd, (char *)&intt) << endl;
    cout << s.isInterleave(bmd, cmd, intr) << endl;
    cout << s.isInterleave(bmd, cmd, intt) << endl;
    return 0;
}
