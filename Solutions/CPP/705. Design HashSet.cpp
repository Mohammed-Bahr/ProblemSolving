// class MyHashSet:

//     def __init__(self):
//         self.hashset = []

//     def add(self, key: int) -> None:
//         if key in self.hashset:
//             return
//         self.hashset.append(key)

//     def remove(self, key: int) -> None:
//         if key not in self.hashset :
//             return

//         self.hashset.remove(key)

//     def contains(self, key: int) -> bool:
//         if key in self.hashset:
//             return True
//         else :
//             return False
// # # Your MyHashSet object will be instantiated and called as such:
// # # obj = MyHashSet()
// # # obj.add(key)
// # # obj.remove(key)
// # # param_3 = obj.contains(key)

#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* next;
    
    node(int v) {
        val = v;
        next = nullptr;
    }
};

class MyHashSet {
private:
    node* root;

public:
    MyHashSet() {
        root = nullptr;
    }

    void add(int key) {
        if (contains(key)) return;

        node* newNode = new node(key);
        newNode->next = root;
        root = newNode;
    }

    void remove(int key) {
        if (!root) return;

        if (root->val == key) {
            node* temp = root;
            root = root->next;
            delete temp;
            return;
        }

        node* curr = root;
        while (curr->next && curr->next->val != key) {
            curr = curr->next;
        }

        if (curr->next) {
            node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }

    bool contains(int key) {
        node* curr = root;
        while (curr) {
            if (curr->val == key)
                return true;
            curr = curr->next;
        }
        return false;
    }
};
    /**
     * Your MyHashSet object will be instantiated and called as such:
     * MyHashSet* obj = new MyHashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     */
