#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0] = 1;

        int prefix = 0;
        int answer = 0;

        for (int num : nums) {
            prefix += num;

            if (mp.count(prefix - k))
                answer += mp[prefix - k];

            mp[prefix]++;
        }

        return answer;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    cout << sol.subarraySum(nums, k) << endl;
    return 0;
}
