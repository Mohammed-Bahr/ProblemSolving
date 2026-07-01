#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        double sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        
        double maxSum = sum;

        for(int i = k; i < n; i++){
            sum += nums[i];       
            sum -= nums[i - k];   
            maxSum = max(maxSum, sum);
        }

        return maxSum / k;
    }
};


int main() {
    string s = "abc";
    string t = "ahbgdc";
    vector <int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    Solution S; 
    cout << S.findMaxAverage(nums , k);

    return 0;
}
