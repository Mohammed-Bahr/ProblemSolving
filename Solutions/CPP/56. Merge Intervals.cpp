#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<int> B;
        vector<int> E;

        if (intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        for (auto &it : intervals)
        {
            B.push_back(it[0]);
            E.push_back(it[1]);
        }

        int n = intervals.size();
        intervals.clear();

        int curStart = B[0];
        int curEnd = E[0];

        for (int j = 1; j < n; ++j)
        {
            if (B[j] <= curEnd) 
            {
                curEnd = max(curEnd, E[j]);
            }
            else 
            {
                intervals.push_back({curStart, curEnd});
                curStart = B[j];
                curEnd = E[j];
            }
        }

        intervals.push_back({curStart, curEnd});

        return intervals;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> intervals = {
        {1, 4}, {0, 2}, {3, 5}};

    vector<vector<int>> result = s.merge(intervals);

    cout << "Merged intervals:\n";
    for (auto &v : result)
    {
        cout << "[" << v[0] << ", " << v[1] << "]\n";
    }

    return 0;
}
