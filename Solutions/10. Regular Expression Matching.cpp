#include <iostream>
#include <vector>
using namespace std;

// Solution class implementing Regular Expression Matching (LeetCode 10)
class Solution {
public:
    // Public interface: checks if string s matches pattern p
    bool isMatch(string s, string p) {
        // Start recursive helper from the beginning of both strings
        return helper(s, p, 0, 0);
    }

private:
    // Recursive helper that checks if s[i:] matches p[j:]
    // i: current index in s,
    // j: current index in p
    bool helper(string& s, string& p, int i, int j) {
        // If we have processed the entire pattern,
        // the string must also be fully consumed for a match
        if (j >= p.size()) return i >= s.size();

        // Determine if the current characters match (consider '.' wildcard)
        bool first = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        // Handle '*' quantifier which applies to the preceding element p[j]
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Two possibilities:
            // 1. Skip the "x*" part entirely (zero occurrences)
            // 2. If current char matches, consume one char from s and keep the pattern index at j
            //    (allowing for multiple occurrences of the preceding element)
            return helper(s, p, i, j + 2)               // case 1: zero occurrences
                || (first && helper(s, p, i + 1, j)); // case 2: one or more occurrences
        }

        // No '*' following – we must have a matching character and move both indices forward
        return first && helper(s, p, i + 1, j + 1);
    }
};

int main() {
    Solution sol;
    // Example test: "aa" vs pattern "a" should output 0 (false)
    cout << sol.isMatch("aa", "a") << endl;
    return 0;
}
