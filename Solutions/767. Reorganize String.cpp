#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        map <char , int> mp;
        for (auto it : s)
        {
            mp[it]++;
        }
        string res = "";
        while (res.size() < s.size())
        {
            for (auto it : mp)
            {
                if (it.second > 0)
                {
                    res += it.first;
                    it.second--;
                }
            }
        }
        
    }
};