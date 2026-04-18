#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1) {
            if (seen.count(n)) return false;
            seen.insert(n);
            string s = to_string(n);
            int res = 0;
            for (char c : s)
                res += pow((c - '0'), 2);
            n = res;
        }
        return true;
    }
};

int main(){
    Solution sol;
    int n = 19;
    cout << sol.isHappy(n) << endl;
    return 0;
}