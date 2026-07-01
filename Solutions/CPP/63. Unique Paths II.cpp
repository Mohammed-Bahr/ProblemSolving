#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1) return 0;

        dp[0][0] = 1;

        for (int c = 1; c < n; ++c)
            dp[0][c] = (obstacleGrid[0][c] == 0 ? dp[0][c - 1] : 0);

        for (int r = 1; r < m; ++r)
            dp[r][0] = (obstacleGrid[r][0] == 0 ? dp[r - 1][0] : 0);

        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (obstacleGrid[r][c] == 1)
                    dp[r][c] = 0;
                else
                    dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


int main() {
    Solution s;
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}