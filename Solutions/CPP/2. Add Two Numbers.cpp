#include <bits/stdc++.h>
using namespace std;
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
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2)
    {
        if (!list1 || !list2) return nullptr;

        stack<int> stack1, stack2;

        // Push digits of first list
        ListNode *current1 = list1;
        while (current1) {
            stack1.push(current1->val);
            current1 = current1->next;
        }

        // Push digits of second list
        ListNode *current2 = list2;
        while (current2) {
            stack2.push(current2->val);
            current2 = current2->next;
        }

        // Convert stacks to strings
        string numStr1, numStr2;
        while (!stack1.empty()) {
            numStr1 += to_string(stack1.top());
            stack1.pop();
        }

        while (!stack2.empty()) {
            numStr2 += to_string(stack2.top());
            stack2.pop();
        }

        // Add the two numbers
        int sumValue = stoi(numStr1) + stoi(numStr2);
        string sumStr = to_string(sumValue);

        // Push digits of result into stack
        stack<int> resultStack;
        for (char digitChar : sumStr) {
            resultStack.push(digitChar - '0');  // convert char to int digit
        }

        // Build the resulting linked list
        ListNode *resultHead = new ListNode(resultStack.top());
        resultStack.pop();

        ListNode *resultCurrent = resultHead;

        while (!resultStack.empty()) {
            resultCurrent->next = new ListNode(resultStack.top());
            resultStack.pop();
            resultCurrent = resultCurrent->next;
        }

        return resultHead;
    }
};


ListNode* buildList(vector<int> v) {
    if (v.empty()) return nullptr;
    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;
    for (int i = 1; i < v.size(); i++) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

// -------------------- MAIN FUNCTION --------------------

int main() {
    // Example input:
    vector<int> v1 = {2, 4, 3};  // Represents number: 7243
    vector<int> v2 = {5, 6, 4};     // Represents number: 564

    ListNode* l1 = buildList(v1);
    ListNode* l2 = buildList(v2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}
