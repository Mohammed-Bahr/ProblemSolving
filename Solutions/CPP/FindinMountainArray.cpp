#include <vector>
#include <iostream>
using namespace std;


// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation

class MountainArray {
private:
    vector<int> arr;

public:
    MountainArray(vector<int> arr) {
        this->arr = arr;
    }

    int get(int index) {
        return arr[index];
    }

    int length() {
        return arr.size();
    }
};


class Solution {
private:

    int findPeak(MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;
        int mid = 0;

        while (left < right) {
            mid = left + (right - left) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }


    int Helper(
        MountainArray &mountainArr,
        int target,
        int left,
        int right,
        bool ascending
    ) {
        while (left <= right) {
            int mid = right - (right - left) / 2;

            if (mountainArr.get(mid) == target) {
                return mid;
            }

            if (ascending) {
                // Ascending: smaller -> larger
                if (mountainArr.get(mid) < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                // Descending: larger -> smaller
                if (mountainArr.get(mid) > target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }


public:

    int findInMountainArray(int target, MountainArray &mountainArr) {

        if (mountainArr.length() == 0) {
            return -1;
        }

        int peak = findPeak(mountainArr);

        // Peak itself
        if (mountainArr.get(peak) == target) {
            return peak;
        }

        // Search ascending part first
        int result = Helper(
            mountainArr,
            target,
            0,
            peak - 1,
            true
        );

        if (result != -1) {
            return result;
        }

        // Search descending part
        return Helper(
            mountainArr,
            target,
            peak + 1,
            mountainArr.length() - 1,
            false
        );
    }
};


int main() {

    vector<int> arr = {0, 5, 3, 1};

    MountainArray mountainArr(arr);

    int target = 3;

    Solution solution;

    int result = solution.findInMountainArray(target, mountainArr);

    cout << result << endl;

    return 0;
}
