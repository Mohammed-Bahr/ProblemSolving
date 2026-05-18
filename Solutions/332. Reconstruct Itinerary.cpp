#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <multiset>

using namespace std;

class Solution {
private:
    void DFS(unordered_map<string, multiset<string>>& AdjList,
             string current,
             vector<string>& itinerary) {

        while (!AdjList[current].empty()) {
            auto it = AdjList[current].begin();
            string next = *it;

            AdjList[current].erase(it);

            DFS(AdjList, next, itinerary);
        }

        itinerary.push_back(current);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, multiset<string>> AdjList;

        for (const auto& ticket : tickets) {
            AdjList[ticket[0]].insert(ticket[1]);
        }

        vector<string> itinerary;

        DFS(AdjList, "JFK", itinerary);

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};

int main() {

    Solution sol;

    vector<vector<string>> tickets = {
        {"JFK","SFO"},
        {"JFK","ATL"},
        {"SFO","ATL"},
        {"ATL","JFK"},
        {"ATL","SFO"}
    };

    vector<string> itinerary = sol.findItinerary(tickets);

    for (const auto& city : itinerary) {
        cout << city << " ";
    }

    cout << endl;

    return 0;
}
