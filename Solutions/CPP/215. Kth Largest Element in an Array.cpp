#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(vector<int>& arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] > pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int pi = partition(nums, low, high);
            if (pi == k - 1)
            {
                return nums[pi];
            }
            else if (pi < k - 1)
            {
                low = pi + 1;
            }
            else
            {
                high = pi - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    cout << s.findKthLargest(nums, 2);
}