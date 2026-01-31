#include <bits/stdc++.h>
using namespace std;

class MySolutionTimeMap {
    unordered_map<string, vector<pair<string,int>>> table;

public:
    MySolutionTimeMap() {}

    void set(string key, string value, int timestamp) {
        table[key].push_back({value, timestamp});
        sort(table[key].begin(), table[key].end(),
             [](pair<string,int> a, pair<string,int> b) {
                 return a.second < b.second;
             });
    }

    string get(string key, int timestamp) {
        if (table.find(key) == table.end()) return "";

        auto &v = table[key];
        string prev = "";

        int left = 0, right = v.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (v[mid].second == timestamp) {
                return v[mid].first;
            }
            else if (v[mid].second < timestamp) {
                prev = v[mid].first;    
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return prev;
    }
};



class TimeMap {
    unordered_map<string, map<int, string>> table;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        table[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (table.find(key) == table.end()) return "";

        auto& m = table[key];
        auto it = m.upper_bound(timestamp);
        if (it == m.begin()) return "";
        --it;
        return it->second;
    }
};


int main() {
    TimeMap timeMap;

    timeMap.set("love", "high", 10);
    timeMap.set("love", "low", 20);

    cout << "\"" << timeMap.get("love", 5)  << "\"" << endl;   // ""
    cout << "\"" << timeMap.get("love", 10) << "\"" << endl;   // high
    cout << "\"" << timeMap.get("love", 15) << "\"" << endl;   // high
    cout << "\"" << timeMap.get("love", 20) << "\"" << endl;   // low
    cout << "\"" << timeMap.get("love", 25) << "\"" << endl;   // low
}
