#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        if (s.size() == 1)
        {
            return s;
        }
        else if (s.size() == 0){
            return "";
        }
        unordered_map <char , int> mp;
        for (auto it : s)
        {
            mp[it]++;
        }
        string res = "";
        for(auto it : mp){
            cout << it.first << " " << it.second << endl;   
        }
        priority_queue <pair <int , char>> pq;
        for (auto it : mp)
        {
            pq.push({it.second , it.first}); // {frequency , character}
        }
        while (pq.size() > 1)
        {
           auto it = pq.top();
           pq.pop();
           auto it1 = pq.top();
           pq.pop();
           //----------------
           res += it.second;
           it.first--;
           //----------------
           res += it1.second;
           it1.first--;
           //----------------
           if (it.first > 0)
           {
               pq.push(it);
           }
           if (it1.first > 0)
           {
               pq.push(it1);
           }

        }
           if (!pq.empty()) {
            if (pq.top().first > 1) {
                return ""; 
            }
            res += pq.top().second;
        }
        return res;
    }
};

int main() {
    Solution Sol;
    cout << "Test " << endl;
    string s = "aaab";
    cout << Sol.reorganizeString(s);
}