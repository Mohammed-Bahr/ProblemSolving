#include <bits/stdc++.h>
using namespace std;

class TimeMap {
    unordered_map< string, vector<pair<string,int> > > table;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        table[key].push_back({value, timestamp});
        sort(table[key].begin(), table[key].end() , [](pair<string,int> a, pair<string,int> b){
            return a.second < b.second;
        });
    }
    
    string get(string key, int timestamp) {
        auto prev = pair<string,int>("",-1);
       for(auto it : table[key]){

        if(it.second == timestamp){
            return it.first;
        }
        else if(it.second > timestamp){
            return prev.first;
        }
        prev = it;
       }
        
       return ""; 
    }
};


int main(){
    cout << "Hello World" << endl;
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl;
    return 0;
}