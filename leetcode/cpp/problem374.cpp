int guess(int num);

class Solution {
    public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        while (start < end) {
            int mid = start + ((end - start) / 2);
            if (guess(mid) <= 0)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};
