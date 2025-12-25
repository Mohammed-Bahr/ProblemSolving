#include <bits/stdc++.h>
using namespace std;

void leftRoutations(vector<int> &nums , int k){
    while(k--){
        int f = nums[0];
        nums.erase(nums.begin());
        nums.push_back(f);
    }
}

int main(){
    vector<int> nums ;
    int n , k ;
    cin >> n >> k;

    for (int i = 1; i < n+1; i++)
    {
        nums.push_back(i);
    }

    leftRoutations(nums,k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}