class Solution {
public:
    int myAtoi(string str) {
        long x = 0;
        int i = 0, mul = 1;
        while (str[i++] == ' ');
            
        if (str[i] == '+') {
            mul = 1; i++;
        } else if (str[i] == '-') {
            mul = -1; i++;
        }
        for (; i < str.length(); i++) {
            if (str[i] < '0' || str[i] > '9') break;
            
            x = x*10 + str[i] - '0';
            if (x*mul >= INT_MAX) return mul*INT_MAX;
            if (x*mul < INT_MIN) return mul*INT_MIN;
        }
        return x*mul;
    }
};
