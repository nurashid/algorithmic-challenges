/*
 * 67. Add Binary
 * 
 * Straight-forward approach.
 * Main difficulty would be implementation
 */  
class Solution {
    public:
        string addBinary(string a, string b) {
            string result = "";
            int i = a.length() - 1, j = b.length() - 1;
            int c = 0;
            while (i >= 0 or j >= 0 or c) {
                int res = (i >= 0 ? a[i] - '0' : 0) +  
                    (j >= 0 ? b[j] - '0' : 0) + c;

                result += (res & 1) + '0';
                c = (res & 2) >> 1 ;
                i--, j--;
            }
            reverse(result.begin(), result.end());
            return result == "" ? "0" : result;
        }
};
