#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int min = word1.size() < word2.size() ? word1.size() : word2.size();
        string result = "";
        char* it1 = &word1[0];
        char* it2 = &word2[0];
        for (int i = 0; i < min; i++) {
            if (i < word1.size()) {
                result += *it1;
                it1++;
            }
            if (i < word2.size()) {
                result += *it2;
                it2++;
            }
        }
        result += word1.substr(min);
        result += word2.substr(min);
        return result;
    }
};


int main(){
    Solution s;
    string result = s.mergeAlternately("abc", "pqr");
    cout << result << endl;
}
