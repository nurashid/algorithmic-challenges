class Solution {
    /*
     * Very tricky
     * Pay close attention to building the Graph
     */
    typedef unordered_set<char> usc;
    typedef unordered_map<char, unordered_set<char>> graph;
    typedef unordered_map<char, int> uci;
public:
    graph buildgraph(vector<string>& words) {
        graph g;
        for (int i = 0; i < words.size(); i++) {
            auto l1 = words[i].length();
            auto match = false;
            for (int j = 0; j < l1; j++) {
                if (g.find(words[i][j]) == g.end())
                    g[words[i][j]] = usc();
                if (i < words.size() - 1) {
                    if (!match and j < words[i+1].length() and words[i+1][j] != words[i][j]) {
                        g[words[i][j]].insert(words[i+1][j]);
                        match = true;
                    }
                }
            }
        }
        return g;
    }
    uci computeindegree(const graph &g) {
        uci indegrees;
        for (auto ni : g) {
            for (auto neighbor : ni.second) {
                indegrees[neighbor]++;
            }
        }
        return indegrees;
    }
    string alienOrder(vector<string>& words) {
        if (words.size() == 1) return words[0];
        graph g = buildgraph(words);
        uci indegrees = computeindegree(g);

        queue<char> toVisit;
        for (auto entry : g) {
   
            if (indegrees.find(entry.first) == indegrees.end())
                toVisit.push(entry.first);
        }
        
        string order;
        for (auto i = 0; i < g.size(); i++) {
            if (toVisit.empty()) return "";
            char c = toVisit.front(); toVisit.pop();
            order += c;
            for (auto neighbor : g[c]) {
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0)
                    toVisit.push(neighbor);
                
            }
        }
        return order;
    }
};
