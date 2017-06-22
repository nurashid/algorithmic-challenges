class Solution {
    // Rough translation from an online source
    // Simple BFS structure
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto dist = 2;
        unordered_set<string> beginSet, endSet, *pBeg, *pEnd;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        while (!beginSet.empty() and !endSet.empty()) {
            if (beginSet.size() > endSet.size())
                pBeg = &beginSet, pEnd = &endSet;
            else
                pBeg = &endSet, pEnd = &beginSet;
            unordered_set<string>tmp;
            for (auto str : *pBeg) {
                wordSet.erase(str);
                for (auto &ch : str) {
                    auto tch = ch;
                    for (char cur = 'a'; cur <= 'z'; cur++) {
                        ch = cur;
                        if (pEnd->find(str) != pEnd->end())
                            return dist;
                        if (wordSet.find(str) != wordSet.end()) {
                            tmp.insert(str);
                            wordSet.erase(str);
                        }
                    }
                    ch = tch;
                }
            }
            dist++;
            swap(*pBeg, tmp);
        }
        return 0;
        
    }
};
