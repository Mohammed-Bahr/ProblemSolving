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


// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     string reorganizeString(string s) {
//         if (s.size() <= 1) return s;

//         unordered_map<char, int> mp;
//         for (char c : s) {
//             mp[c]++;
//         }

//         priority_queue<pair<int, char>> pq;
//         for (auto it : mp) {
//             pq.push({it.second, it.first});
//         }

//         string res = "";

//         while (pq.size() >= 2) {
//             auto it = pq.top(); pq.pop();
//             auto it1 = pq.top(); pq.pop();

//             res += it.second;
//             res += it1.second;

//             it.first--;
//             it1.first--;

//             if (it.first > 0) pq.push(it);
//             if (it1.first > 0) pq.push(it1);
//         }

//         // لو فاض عنصر واحد
//         if (!pq.empty()) {
//             if (pq.top().first > 1) {
//                 return ""; // مستحيل نعيد ترتيب السلسلة
//             }
//             res += pq.top().second;
//         }

//         return res;
//     }
// };

// int main() {
//     Solution Sol;
//     string s = "aaab";
//     cout << Sol.reorganizeString(s);
// }
