class Solution {
public:
    // Check for overflow
    // Algorithm:
    // 1. Check for negativity
    // 2. Make number positive
    // 3. have output = 0
    // 4. for every rightmost digit of the integer
    int reverse(int x) {
        int negative = (x < 0) ? true : false;
        if (negative)
            x = -x;
        int out = 0;
        while (x) {
            // Here we are checking for overflow
            int tout = out*10;
            if (tout/10 != out)
                return 0;
            else
                out = tout;
            int number = x%10;
            out += number;
            x /= 10;
        }
        return (negative) ? - out : out ;
        
    }
};
