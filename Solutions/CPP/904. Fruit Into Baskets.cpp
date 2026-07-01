#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int maxFruits = 0;
        unordered_map<int, int> mp; // fruit -> count

        for (int right = 0; right < fruits.size(); right++) {
            mp[fruits[right]]++;

            while (mp.size() > 2) {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);
                left++;
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};

int main() {
    Solution sol;
    vector<int> fruits = {1,2,3,2,2};
    cout << sol.totalFruit(fruits) << endl;
}
