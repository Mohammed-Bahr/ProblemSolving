#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto &token : tokens) {
            if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1)) {
                st.push(stoi(token));
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            }
        }
        return st.top();
        
    }
};

int main(){
    cout << "hello worlds" << endl;
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << sol.evalRPN(tokens) << endl; // ((2 + 1) * 3) = 9
    return 0;
}