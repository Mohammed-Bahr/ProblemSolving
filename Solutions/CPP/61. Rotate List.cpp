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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        for (int i = 1; i <= k; i++) {

            ListNode* temp = head;
            ListNode* prev = nullptr;

            while (temp->next) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = nullptr;
            temp->next = head;
            head = temp;
        }

        return head;
    }



    ListNode* obtimized_rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k = k % len ;
        int numOfSteps_To_newHead = len - k;

        ListNode * newtail = head;
        for (int i = 1 ; i < numOfSteps_To_newHead ; i++) {
            newtail = newtail->next;
        }

        head = newtail->next;
        newtail->next = nullptr ; // cut the link
        
        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Linked list: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    int k = 2;

    cout << "Original list: ";
    printList(head);

    head = sol.obtimized_rotateRight(head, k);

    cout << "Rotated list: ";
    printList(head);

    return 0;
}
