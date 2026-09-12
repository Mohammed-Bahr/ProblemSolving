#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove the element that is now outside the window
            if (i > k) {
                set.erase(nums[i - k - 1]);
            }

            // Check if the current element exists in the set
            if (set.count(nums[i])) {
                return true;
            }

            // Add the current element to the set
            set.insert(nums[i]);
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    bool result = solution.containsNearbyDuplicate(nums, k);
    cout << result << endl;
    return 0;
}
