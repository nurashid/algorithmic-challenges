class Solution {
    /* Trick is to remembering to do (A - 1)
     */ 
public:
    string convertToTitle(int A) {
        string result = "";
        while (A) {
            result.insert(0, 1, (char) ('A' + (A - 1) % 26));
            A = (A-1) / 26;
        }
        return result;
    }
};
