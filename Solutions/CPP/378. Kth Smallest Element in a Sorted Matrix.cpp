#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        vector<int> vec;
        for (auto it : matrix){
            for (auto iit : it){
                vec.push_back(iit);
            }
        }


        sort(vec.begin() , vec.end());
        return vec[k-1];
    }
};



int main(){
    Solution S;

    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    vector<vector<int>> matrix1 = {{-5}};

    cout << S.kthSmallest(matrix1 , 1);
}