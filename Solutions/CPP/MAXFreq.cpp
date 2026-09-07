#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class FreqStack {
public:
    unordered_map<int,int> f;
    unordered_map<int,vector<int>> mp;
    int m=0;

    FreqStack() {

    }

    void push(int val) {
        f[val]++;
        int freq=f[val];
        mp[freq].push_back(val);
        m=max(m,freq);
    }

    int pop() {
        int ans=mp[m].back();
        mp[m].pop_back();
        f[ans]--;
        if(mp[m].empty())
        m--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */


int main() {
    FreqStack* obj = new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);
    int param_2 = obj->pop();
    cout << param_2 << endl;
    return 0;
}
