#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        queue<char> q;
        stack<char> st;

        for (char c : s) {
            if (isalpha(c) || isdigit(c)) {
                char x = tolower(c);
                q.push(x);
                st.push(x);
            }
        }

        while (!q.empty()) {
            if (q.front() != st.top()) {
                return false;
            }
            q.pop();
            st.pop();
        }

        return true;
    }
};

int main() {
    Solution Sol;
    string s = "A man, a plan, a canal: Panama";
    cout << Sol.isPalindrome(s); 
}
