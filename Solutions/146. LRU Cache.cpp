#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;
    list<int> lru; // keeps order: front = most recent
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        // move key to front (most recently used)
        lru.erase(cache[key].second);
        lru.push_front(key);
        cache[key].second = lru.begin();

        return cache[key].first;
    }

    void put(int key, int value) {
        // if key already exists
        if (cache.find(key) != cache.end()) {
            lru.erase(cache[key].second);
        }
        // if cache is full
        else if (cache.size() == cap) {
            int lruKey = lru.back();
            lru.pop_back();
            cache.erase(lruKey);
        }

        // insert/update key
        lru.push_front(key);
        cache[key] = {value, lru.begin()};
    }
};


int main() {
    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl; // returns 1
    obj->put(3, 3);              // evicts key 2
    cout << obj->get(2) << endl; // returns -1 (not found)
    obj->put(4, 4);              // evicts key 1
    cout << obj->get(1) << endl; // returns -1 (not found)
    cout << obj->get(3) << endl; // returns 3
    cout << obj->get(4) << endl; // returns 4

    return 0;
}