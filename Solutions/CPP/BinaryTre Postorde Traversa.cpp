#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
    // This function answers:
    // "If each subarray sum must be <= limit,
    //  can we split nums into at most k subarrays?"
    //
    // We use a greedy approach:
    // - Keep adding numbers to the current subarray.
    // - If adding the next number would make the sum > limit,
    //   start a new subarray with that number.
    //
    // Greedy works here because all numbers are non-negative.
    bool canSplit(const vector<int>& nums, int k, long long limit) {
        int parts = 1;        // We need at least one subarray
        long long sum = 0;    // Current subarray sum

        for (int x : nums) {
            // If adding x exceeds the allowed limit,
            // we must cut before x and start a new subarray.
            if (sum + x > limit) {
                parts++;
                sum = x;

                // If we already need more than k subarrays,
                // then this limit is impossible.
                if (parts > k) return false;
            } else {
                // Otherwise, add x to the current subarray.
                sum += x;
            }
        }

        // We managed to split nums into at most k subarrays
        // while keeping every subarray sum <= limit.
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        // The answer is the minimum possible largest subarray sum.
        //
        // Lower bound: the largest single element.
        // Because any subarray containing that element will have sum
        // at least that element.
        //
        // Upper bound: the sum of all elements.
        // Because we can put everything into one subarray.
        long long lo = 0;
        long long hi = 0;

        for (int x : nums) {
            lo = max(lo, (long long)x);
            hi += x;
        }

        // Binary search for the smallest limit such that
        // canSplit(nums, k, limit) is true.
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            // If we can split with maximum sum <= mid,
            // then mid is possible. Try to find a smaller answer.
            if (canSplit(nums, k, mid)) {
                hi = mid;
            } else {
                // Otherwise, mid is too small.
                // We need a larger limit.
                lo = mid + 1;
            }
        }

        // lo == hi is the minimum possible largest subarray sum.
        return (int)lo;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << sol.splitArray(nums, k) << endl;
    return 0;
}
