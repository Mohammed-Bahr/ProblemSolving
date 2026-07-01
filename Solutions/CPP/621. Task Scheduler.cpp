#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char c : tasks)
            freq[c - 'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());

        int countMax = 0;
        for (int f : freq)
            if (f == maxFreq)
                countMax++;

        int totalTasks = tasks.size();

        int result = (maxFreq - 1) * (n + 1) + countMax;

        return max(totalTasks, result);
    }
};

int main()
{
  string s = "abc";
  string t = "ahbgdc";
  vector<int> nums = {1, 12, -5, -6, 50, 3};
  int k = 4;
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;

  Solution S;
  cout << S.leastInterval(tasks, n);

  return 0;
}
