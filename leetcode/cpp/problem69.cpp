class Solution {
    /* Few ways to compute square:
     * 1. Newton's methond
     * 2. Binary Search
     */
public:
    int mySqrt(int x) {
        long r = x;
        
        while (r*r > x) {
            r = (r + x/r) / 2;
        }
        return r;
    }
};
