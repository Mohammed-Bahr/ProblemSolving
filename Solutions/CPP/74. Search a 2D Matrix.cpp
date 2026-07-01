#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0 ;
        int r = matrix[0].size() - 1 ;
        int i = 0;
        while (l <= r && i < matrix.size()){
           
            if(matrix[i][r] >= target && matrix[i][l] <= target){
                int mid = (l + r) / 2 ;
                if(matrix[i][mid] == target){
                    return true;
                }
                else if(matrix[i][mid] > target){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }

            }
            else {
                i++;
            }
            
        }
        return false;
    }
};



int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 10;
    cout << sol.searchMatrix(matrix,target) << endl;
}