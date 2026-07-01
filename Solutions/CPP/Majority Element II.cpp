#include <vector>
#include <map>
#include <iostream>
using namespace std ;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> pairs;
        map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        for (auto& [num, count] : map) {
            if (count > nums.size() / 3) {
                pairs.push_back(num);
            }
        }
        return pairs;
    }
};

int main () {
    Solution sol;
    vector<int> nums = {3,2,3};
    vector<int> result = sol.majorityElement(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
