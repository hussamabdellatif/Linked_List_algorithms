// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.



// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
  };


#include <vector>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode(0);
        int carry   = 0;
        ListNode* current = head;
        int sum;
        int value1;
        int value2;
        while(l1 || l2 ){
            value1 = (l1) ? l1->val : 0;
            value2 = (l2) ? l2->val : 0;
            sum = value1 + value2;
            if(carry) sum++;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* xr = new ListNode(sum);
            l1 = (l1) ? l1->next : l1 ;
            l2 = (l2) ? l2->next : l2 ;
            current->next = xr;
            current = xr;
        }

        if(carry){
        ListNode* xr = new ListNode(1);
        current->next = xr;
        current = xr;
        }

        return head->next;


    }


    /*
    void rev(ListNode* current, ListNode* prev, ListNode** head){
        if(current->next ==NULL){
            *head = current;
             current->next = prev;
             return;
        }

        ListNode* next = current->next;
        current->next = prev;
        rev(next, current, head);
    }
   */


};
