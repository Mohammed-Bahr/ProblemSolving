
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (list1) curr->next = list1;
        if (list2) curr->next = list2;

        ListNode* res = head->next;
        delete head;
        return res;
    }
};

// Helper function to create a linked list from array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for (int i = 1; i < size; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    if (!head) {
        cout << "[]" << endl;
        return;
    }

    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "]" << endl;
}

// Helper function to free memory
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    // Test Case 1: Both lists have elements
    cout << "Test Case 1:" << endl;
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    ListNode* result1 = solution.mergeTwoLists(list1, list2);
    cout << "Merged: ";
    printList(result1);
    deleteList(result1);
    cout << endl;

    // Test Case 2: Empty lists
    cout << "Test Case 2:" << endl;
    ListNode* list3 = nullptr;
    ListNode* list4 = nullptr;

    cout << "List 1: ";
    printList(list3);
    cout << "List 2: ";
    printList(list4);

    ListNode* result2 = solution.mergeTwoLists(list3, list4);
    cout << "Merged: ";
    printList(result2);
    deleteList(result2);
    cout << endl;

    // Test Case 3: One empty list
    cout << "Test Case 3:" << endl;
    int arr5[] = {0};
    ListNode* list5 = nullptr;
    ListNode* list6 = createList(arr5, 1);

    cout << "List 1: ";
    printList(list5);
    cout << "List 2: ";
    printList(list6);

    ListNode* result3 = solution.mergeTwoLists(list5, list6);
    cout << "Merged: ";
    printList(result3);
    deleteList(result3);

    return 0;
}
