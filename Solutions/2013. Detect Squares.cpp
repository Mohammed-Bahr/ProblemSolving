class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0) {
            // Step 2: Find the smallest element to the right of i that is greater than nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix starting at i+1
        reverse(nums.begin() + i + 1, nums.end());
    }
};
