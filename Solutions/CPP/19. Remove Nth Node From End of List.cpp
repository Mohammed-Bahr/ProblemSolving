

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        int size = 0;
        ListNode* dummy = head;

        // 1. Count size
        while (dummy) {
            size++;
            dummy = dummy->next;
        }

        // 2. Map node positions from end (using pointer as key)
        unordered_map<ListNode*, int> dp;
        ListNode* temp = head;
        int posFromEnd = size;

        while (temp) {
            dp[temp] = posFromEnd--;
            temp = temp->next;
        }

        // 3. If head is the node to remove
        if (dp[head] == n) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        // 4. Find previous node
        ListNode* curr = head;
        while (curr && curr->next) {
            if (dp[curr->next] == n) {
                ListNode* D = curr->next;
                curr->next = curr->next->next;
                delete D;
                return head;
            }
            curr = curr->next;
        }

        return head;
    }
};


// Another optimized approach without extra space
class SolutionOptimized {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Use a dummy node to handle the case where the head itself is removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // 1. Move fast ahead by n + 1 steps to create the gap
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // 2. Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 3. slow is now at the node BEFORE the one we want to delete
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Free memory
        delete nodeToDelete;
        
        // Return the head (dummy->next covers the case where head changed)
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        
        return newHead;
    }
};


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// =============================================
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution s;
    
    int n = 2; // remove 2nd from end (should remove 4)
    head = s.removeNthFromEnd(head, n);

    cout << "After removing " << n << "-th from end: ";
    printList(head);

    return 0;
}
