class Solution {
    /*
     * Solution approach:
     * 1. find how many anti/diagonal lines there could be
     * 2. find out relationship between # of lines and # of row+col
     * 3. then devise your algorithm
     */
    public:
    vector<int> findDiagonalOrder(vector<vector<int>>& A) {
        vector<int> result;
        if (A.size() == 0)
            return result;
        int nc = A[0].size(),
            nr = A.size();
        int lines = nc + nr - 1;
        for (auto lineNum = 0; lineNum < lines; lineNum++) {
            if (lineNume % 2 != 0) {
                auto y = (lineNum < nc) ? 0 : lineNum - nc + 1;
                auto x = (y == 0) ? lineNum : nc - 1;
                while (y < nr and x >= 0) {
                    result.push_back(A[y][x]);
                    y++, x--;
                }
            } else {
                auto x = (lineNum < nr) ? 0 : lineNum - nr + 1;
                auto y = (x == 0) ? lineNum : nr - 1;
                while (x < nc and y >= 0) {
                    result.push_back(A[y][x]);
                    y--, x++;
                }
            }
        }
        return result;
    }
};
