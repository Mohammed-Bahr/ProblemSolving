#include <unordered_map>
#include <list>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LFUCache {
private:
    struct Node {
        int value;
        int freq;
        list<int>::iterator it; // position inside freqList[freq]
    };

    unordered_map<int, Node> cache;          // key -> node
    unordered_map<int, list<int>> freqList;  // freq -> keys (front = LRU, back = MRU)
    int capacity;
    int minFreq = 0;

    // Move key to the next frequency bucket
    void touch(int key) {
        Node& node = cache[key];
        int f = node.freq;

        freqList[f].erase(node.it);
        if (freqList[f].empty()) {
            freqList.erase(f);
            if (minFreq == f) minFreq++;
        }

        node.freq = f + 1;
        freqList[f + 1].push_back(key);
        node.it = prev(freqList[f + 1].end());
    }

public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto found = cache.find(key);
        if (found == cache.end()) return -1;

        touch(key);
        return cache[key].value;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        auto found = cache.find(key);
        if (found != cache.end()) {
            found->second.value = value;
            touch(key);
            return;
        }

        // Evict LFU (ties broken by LRU) in O(1)
        if ((int)cache.size() == capacity) {
            int evictKey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            if (freqList[minFreq].empty()) freqList.erase(minFreq);
            cache.erase(evictKey);
        }

        // Insert new key with frequency 1
        freqList[1].push_back(key);
        cache[key] = {value, 1, prev(freqList[1].end())};
        minFreq = 1;
    }
};

int main() {
    vector<string> result;
    LFUCache* cache = new LFUCache(2);
    result.push_back("null");
    cache->put(1, 1);
    result.push_back("null");
    cache->put(2, 2);
    result.push_back("null");
    result.push_back(to_string(cache->get(1)));
    cache->put(3, 3);
    result.push_back("null");
    result.push_back(to_string(cache->get(2)));
    result.push_back(to_string(cache->get(3)));
    cache->put(4, 4);
    result.push_back("null");
    result.push_back(to_string(cache->get(1)));
    result.push_back(to_string(cache->get(3)));
    result.push_back(to_string(cache->get(4)));

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        if (i != 0) cout << ", ";
        cout << result[i];
    }
    cout << "]" << endl;

    delete cache;
    return 0;
}
