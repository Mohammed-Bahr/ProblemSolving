

// class MyCircularQueue {
// private:
//     vector<int> queue;
//     int size;
//     int *front;
//     int *rear;

// public:
//     MyCircularQueue(int k) {
//         size = k;
//         front = new int(-1);
//         rear = new int(-1);
//     }

//     bool enQueue(int value) {
//         int *newValue = new int(value) ;

//         if (isFull()) {
//             return false;
//         }
//         else if (isEmpty()) {
//             front = newValue ;
//             rear = newValue;
//             return true;
//         }
//         else{
//             int oldRear = *rear;
//             *rear = value
//             return true;
//         }


//         return false

//     }

//     bool deQueue() {

//     }

//     int Front() {

//     }

//     int Rear() {

//     }

//     bool isEmpty() {
//         if (*front == -1 && *rear == -1) {
//             return true;
//         }
//         return false;
//     }

//     bool isFull() {
//         if (*front == 0 && *rear == size - 1) {
//             return true;
//         }
//         return false;
//     }
// };

// /**
//  * Your MyCircularQueue object will be instantiated and called as such:
//  * MyCircularQueue* obj = new MyCircularQueue(k);
//  * bool param_1 = obj->enQueue(value);
//  * bool param_2 = obj->deQueue();
//  * int param_3 = obj->Front();
//  * int param_4 = obj->Rear();
//  * bool param_5 = obj->isEmpty();
//  * bool param_6 = obj->isFull();
//  */

#include <vector>

class MyCircularQueue {// TC : O(K) & SC : O(K)
public:


    int n;
    ListNode* head;
    ListNode* curr;
    ListNode* prev;


    MyCircularQueue(int k) {// TC : O(k) & SC : O(K)
       n = k;

        ListNode* h = new ListNode(-1);
        ListNode* temp = h;

       for(int i=1;i<k;i++){
            temp->next = new ListNode(-1);
            temp = temp->next;
       }

       temp->next = h;

       head = h;
       curr = head;
       prev = head;
    }

    int sz = 0;


    bool enQueue(int value) {// TC : O(1) & SC : O(1)

       if(sz < n){
            curr->val = value;
            prev = curr;
            curr = curr->next;
            sz++;
            return true;
       }else{
            return false;
       }

    }


    bool deQueue() {// TC : O(1) & SC : O(1)

        if(sz > 0){
           ListNode* temp = head;
           head = head->next;
           temp->val = -1;

            sz--;
            return true;

        }else{
            return false;
        }
    }


    int Front() {// TC : O(1) & SC : O(1)
        return head->val;
    }


    int Rear() {// TC : O(1) & SC : O(1)
        return prev->val;
    }


    bool isEmpty() {// TC : O(1) & SC : O(1)
        if(sz == 0){
            return true;
        }else{
            return false;
        }
    }


    bool isFull() {// TC : O(1) & SC : O(1)
        if(sz == n){
            return true;
        }else{
            return false;
        }
    }

};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
