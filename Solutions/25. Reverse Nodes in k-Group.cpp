// #include <bits/stdc++.h>
// using namespace std;
// //Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
 
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if (head == nullptr || k <= 1) {
//             return head;
//         }
//         //------------------------------
//         if (head->next->next == nullptr && k == 2){
//             ListNode* temp = head->next;
//             head->next = nullptr;
//             temp->next = head;
//             return temp;
//         }

//         //-------------------------------
//         int count = 0; 
//         int sizeHead = 0;
//         int sizeRes = 0;
//         stack<int> stk;
//         ListNode* curr = head;
//         ListNode* tail = new ListNode(0);
//         ListNode* res = tail;
//         while (curr != nullptr) {
//             count++;
//             sizeHead++;
//             stk.push(curr->val);
//             curr = curr->next;
//             if (count == k){
//                 sizeRes += k;
//                 count = 0;
//                 while (!stk.empty()) {
//                     tail->next = new ListNode(stk.top());
//                     tail = tail->next;
//                     stk.pop();
//                 }
//             }
//         }
//         ListNode* temp = head;
//         if (sizeHead > sizeRes){
//             while(sizeRes--){
//                 temp = temp->next;
//             }
//         }
//         tail->next = temp;
//         return res->next;
//     }
// };



// int main() {
//     // Example usage:
//     ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
//     int k = 1;

//     Solution sol;
//     ListNode* newHead = sol.reverseKGroup(head, k);

//     // Print the reversed list
//     ListNode* curr = newHead;
//     while (curr != nullptr) {
//         cout << curr->val << " ";
//         curr = curr->next;
//     }
//     cout << endl;

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) {
            return head;
        }

        int count = 0; 
        int sizeHead = 0;
        int sizeRes = 0;

        stack<int> stk;
        ListNode* curr = head;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (curr != nullptr) {
            count++;
            sizeHead++;
            stk.push(curr->val);
            curr = curr->next;

            if (count == k) {
                sizeRes += k;
                count = 0;
                while (!stk.empty()) {
                    tail->next = new ListNode(stk.top());
                    tail = tail->next;
                    stk.pop();
                }
            }
        }

        // Clear unused stack values (important)
        while (!stk.empty()) stk.pop();

        // Attach remaining nodes
        ListNode* temp = head;
        while (sizeRes--) {
            temp = temp->next;
        }
        tail->next = temp;

        return dummy->next;
    }
};

int main() {
    ListNode* head = new ListNode(1,
        new ListNode(2,
        new ListNode(3,
        new ListNode(4,
        new ListNode(5)))));

    int k = 3;

    Solution sol;
    ListNode* newHead = sol.reverseKGroup(head, k);

    while (newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
}
