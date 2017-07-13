/*
 * Triangle:
 * Basic idea is to start from the
 * bottom and then go up
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        for (int j = height-1; j > 0; j--) {
            for (int i = 0; i < j; i++) {
                triangle[j-1][i] += min(triangle[j][i], triangle[j][i+1]);
            }
        }
        return triangle[0][0];
    }
};
