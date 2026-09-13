#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(), weights.end());
        int n = weights.size();
        int max_weight = 0;
        int min_weight = weights[0];
        for (int w : weights) {
            min_weight = max(min_weight, w);
            max_weight += w;
        }

        int right = max_weight;
        int left = min_weight ;

        for (int w : weights) {
            right += w;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            int days_needed = 1, current_capacity = 0;
            for (int w : weights) {
                if (current_capacity + w > mid) {
                    days_needed++;
                    current_capacity = 0;
                }
                current_capacity += w;
            }
            if (days_needed > days) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};


int main() {
    Solution s;
    vector<int> weights = {1,2,3,1,1};
    int days = 4;
    cout << s.shipWithinDays(weights, days) << endl;
    return 0;
}
