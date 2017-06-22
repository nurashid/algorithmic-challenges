/* 
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2
 */
class Solution {
    // O(N) : N is the number of digits
    void addNumber(vector<int>& arr, int offset, int num) {
        while (num) {
            arr[offset] += num % 10;
            num /= 10;
            offset--;
        }
    }
    string makenumber(vector<int>& arr) {
        auto i = 0;
        string result = "";
        while (arr[i++] == 0);
        for (; i < arr.size(); i++)
            result += to_string(arr[i]);
        return result;
    }
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length(),
            l2 = num2.length();
        vector<int>num(l1+l2, 0);
        for (int i = l1 - 1; i >= 0; i--)
            for (int j = l2 - 1; j >= 0; j--) {
                addNumber(num, i + j + 1, (num1[i] - '0')*(num2[j] - '0'));
                cout << i << " " << j  << endl;
            }
        return makenumber(num);
    }
};
