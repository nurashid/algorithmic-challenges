class Solution {
public:
    bool isValid(string s) {
        char openbracket[] = { '(', '{', '['};
        char closebracket[] = { ')', '}', ']' };

        list<int> stack;
        for (int i = 0; i < s.length(); i++) {
            for (int k = 0; k < 3; k++) {
                if (openbracket[k] == s[i])
                    stack.push_back(k);
            }
            for (int k = 0; k < 3; k++) {
                if (closebracket[k] == s[i]) {
                    if (stack.empty())
                        return false;
                    int bracket = stack.back(); 
                    if (bracket != k)
                        return false;
                    stack.pop_back();
                    
                }
            }
        }
        return stack.empty();
    }
};
