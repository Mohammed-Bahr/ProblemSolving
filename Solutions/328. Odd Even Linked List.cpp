#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return head;

        int len = 1;
        ListNode *final = head;
        while (final->next) {
            len++;
            final = final->next;
        }

        ListNode *tail = final; 
        ListNode *curr = head;
        ListNode *prev = nullptr;

        for (int i = 0; i <= len - 1; i++)
        {
            if (i % 2 == 1)
            {
                ListNode *temp = curr;
                curr = curr->next;

                if(prev) prev->next = curr;

                tail->next = temp;
                tail = tail->next;
                tail->next = nullptr;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};




// Helper function to create a linked list from a vector
ListNode* buildList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example input
    vector<int> arr = {1,2,3,5,6,4,7,8};

    // Build linked list
    ListNode* head = buildList(arr);

    cout << "Original List: ";
    printList(head);

    Solution s;
    ListNode* result = s.oddEvenList(head);

    cout << "Modified List: ";
    printList(result);

    return 0;
}