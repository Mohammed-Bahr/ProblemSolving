// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
//     public:
//         vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//            int left = 0;
//            int right = k -1 ;
//            vector <int> res;
//             int maxi = INT_MIN;
//            for (int i = 0; i < k; i++) {
//                 maxi = max(maxi, nums[i]);
//            }
//            res.push_back(maxi);
//            for (int i = k - 1 ; i < nums.size(); i++) {
//                 maxi = max(maxi, nums[i]);
//                 res.push_back(maxi);
//                 maxi = INT_MIN;
//            }
//            return res;
//         }
//     };

// int main(){
//     Solution S;
//     vector<int> nums = {1,3,-1,-3,5,3,6,7};
//     int k = 3;
//     vector<int> res = S.maxSlidingWindow(nums, k);
//     for (int i = 0; i < res.size(); i++) {
//         cout << res[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> res;

//         int left = 0;
//         int right = k - 1;

//         int maxi = nums[0];
//         for (int i = 1; i < k; i++) {
//             maxi = max(maxi, nums[i]);
//         }
//         res.push_back(maxi);

//         while (right + 1 < nums.size()) {
//             right++;

//             if (nums[left] == maxi) {
//                 maxi = nums[left + 1];
//                 for (int i = left + 2; i <= right; i++) {
//                     maxi = max(maxi, nums[i]);
//                 }
//             } else {
//                 maxi = max(maxi, nums[right]);
//             }

//             left++;
//             res.push_back(maxi);
//         }

//         return res;
//     }
// };

// int main() {
//     Solution S;
//     vector<int> nums = {1,3,-1,-3,5,3,6,7};
//     int k = 3;

//     vector<int> res = S.maxSlidingWindow(nums, k);
//     for (int x : res)
//         cout << x << " ";

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int left = 0;
//         int right = k - 1;
//         vector<int> res;
//         int maxi = INT_MIN;
//         int index = -1;
//         // for first window
//         for (int i = 0; i < k; i++){
//             if(nums[i] > maxi){
//                 maxi = nums[i];
//                 index = i;
//             }
//         }
//         res.push_back(maxi);
//         while (right++ < nums.size()){
//             left++;
//             right++;
//             if (index >= left){
//                 if (nums[right] >= maxi){
//                     maxi = nums[right];
//                     index = right;
//                     res.push_back(maxi);
//                 }
//                 else{
//                     res.push_back(maxi);
//                 }
//             }
//             else{
//                 maxi = nums[left];
//                 index = left;
//                 for (int i = left; i <= right; i++){
//                     if (nums[i] >= maxi){
//                         maxi = nums[i];
//                         index = i;
//                     }
//                 }
//                 res.push_back(maxi);
//             }
//         }
//         return res;
//     }
// };

// int main() {
//     Solution S;
//     vector<int> nums = {1,3,-1,-3,5,3,6,7};
//     int k = 3;
//     vector<int> res = S.maxSlidingWindow(nums, k);

//     for (int x : res)
//         cout << x << " ";

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = k - 1;
        vector<int> res;

        int maxi = INT_MIN;
        int index = -1;

        // first window
        for (int i = 0; i < k; i++) {
            if (nums[i] >= maxi) {
                maxi = nums[i];
                index = i;
            }
        }
        res.push_back(maxi);

        // slide window
        while (right + 1 < nums.size()) {
            right++;
            left++;

            // if max still inside window
            if (index >= left) {
                if (nums[right] >= maxi) {
                    maxi = nums[right];
                    index = right;
                }
            }
            // if max went out
            else {
                maxi = nums[left];
                index = left;
                for (int i = left + 1; i <= right; i++) {
                    if (nums[i] >= maxi) {
                        maxi = nums[i];
                        index = i;
                    }
                }
            }

            res.push_back(maxi);
        }

        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> res = S.maxSlidingWindow(nums, k);
    for (int x : res)
        cout << x << " ";

    return 0;
}
