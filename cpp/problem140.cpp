Class Solution {
    // Memoization
    // Accepted. Runtime: 9 ms
    unordered_set<string> dict;
    unordered_map<string, vector<string>> memo;
    vector<string> wordBreakHelperMemo(string input)
    {
        
        if (memo.find(input) != memo.end())
            return memo[input];
        vector<string> result;
        if (dict.find(input) != dict.end())
            result.push_back(input);
        
        for (int l = 1; l <= input.length(); l++) {
            string word = input.substr(l);
            if (dict.find(word) != dict.end()) {
                string remaining = input.substr(0,l);
                vector<string> remainingResult = wordBreakHelperMemo(remaining);
                vector<string> prev;
                for (auto str : remainingResult)
                    prev.push_back(str + " " + word);
                
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        memo[input] = result;
        return memo[input];
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict.insert(wordDict.begin(), wordDict.end());
        vector<string> sentences, sofar;
        sentences = wordBreakHelperMemo(s);
        return sentences;
    }
};

