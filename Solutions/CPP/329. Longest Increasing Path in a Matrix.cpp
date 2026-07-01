#include <vector>
#include <iostream>
using namespace std ;

class Solution {
public:
    int dfs(int row , int col , int prev , vector<vector<int>>& matrix, vector<vector<int>>& LIP) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        if (row < 0 || col < 0 || row >= ROWS || col >= COLS || matrix[row][col] <= prev) {
            return 0;
        }
        if (LIP[row][col] != 0) {
            return LIP[row][col];
        }
        int maxLIP = 1;
        maxLIP = max(maxLIP,1 + dfs(row + 1, col, matrix[row][col], matrix, LIP));
        maxLIP = max(maxLIP,1 + dfs(row - 1, col, matrix[row][col], matrix, LIP));
        maxLIP = max(maxLIP,1 + dfs(row, col + 1, matrix[row][col], matrix, LIP));
        maxLIP = max(maxLIP,1 + dfs(row, col - 1, matrix[row][col], matrix, LIP));
        LIP[row][col] = maxLIP ;
        return LIP[row][col];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        vector<vector<int>> LIP(ROWS, vector<int>(COLS, 0));
        int maxLIP = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                maxLIP = max(maxLIP, dfs(i, j, -1, matrix, LIP));
            }
        }
        return maxLIP;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    cout << sol.longestIncreasingPath(matrix) << endl;
    return 0;
}
