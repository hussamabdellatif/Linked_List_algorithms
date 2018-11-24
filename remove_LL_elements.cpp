// Remove all elements from a linked list of integers that have value val.
//
// Example:
//
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5

#include<cstdio>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
       return rm(head, NULL, head, val);
    }

    ListNode* rm(ListNode* current, ListNode* prev, ListNode* head, int val){
        if(!current) return head;
        if(current->val == val){
            if(prev == NULL){ // current is head
                head = head->next;
                current = head;
                prev = NULL;
            }else{
                prev->next = current->next;
                current = current->next;
            }
        }else{
            prev = current;
            current = current->next;
        }

        return rm(current, prev, head, val);


    }
};
