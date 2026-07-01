
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
private:
    void merge(int arr[], int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int *L = new int[n1];
        int *R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }

        while (i < n1)
            arr[k++] = L[i++];

        while (j < n2)
            arr[k++] = R[j++];

        delete[] L;
        delete[] R;
    }

    void mergeSort(int arr[], int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head)
            return head;

        // 1) احسب الحجم
        int size = 0;
        ListNode *temp = head;
        while (temp)
        {
            size++;
            temp = temp->next;
        }

        // 2) اعمل array بالحجم
        int *arr = new int[size];

        // 3) نقل القيم
        temp = head;
        int index = 0;
        while (temp)
        {
            arr[index++] = temp->val;
            temp = temp->next;
        }

        // 4) sort
        mergeSort(arr, 0, size - 1);

        // 5) رجّع القيم
        ListNode *curr = head;
        for (int i = 0; i < size; i++)
        {
            curr->val = arr[i];
            curr = curr->next;
        }

        delete[] arr;
        return head;
    }
};

class optimized_Solution
{
private:
    // find middle using slow/fast pointers
    ListNode *getMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // merge two sorted lists
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1)
            tail->next = l1;
        else
            tail->next = l2;

        return dummy.next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // 1) split list
        ListNode *middle = getMiddle(head);
        ListNode *right = middle->next;
        middle->next = nullptr; // split

        // 2) sort each half
        ListNode *leftSorted = sortList(head);
        ListNode *rightSorted = sortList(right);

        // 3) merge sorted halves
        return merge(leftSorted, rightSorted);
    }
};

int main()
{
    // Create a sample linked list: 4 -> 2 -> 1 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution s;
    head = s.sortList(head);

    // Print sorted list
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }

    //===========================================
    // optimized one
    // create a list: 4 -> 2 -> 1 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    optimized_Solution s;
    head = s.sortList(head);

    // print sorted list
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}