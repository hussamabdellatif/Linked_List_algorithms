// //Partition List
// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the two partitions.
//
// Example:
//
// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5

#include <cstdio>
using namespace std;


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:


    ListNode* partition(ListNode* head, int x) {
        ListNode bueno(0);        ListNode no_bueno(0);
        ListNode* _bueno = &bueno; ListNode* _no_bueno = &no_bueno;
        while(head){
            if(head->val < x){
                _bueno->next = head;
                _bueno = _bueno->next;
            }else{
                _no_bueno->next = head;
                _no_bueno = _no_bueno->next;
            }
            head = head->next;
        }
        _no_bueno->next=NULL;
        _bueno->next = no_bueno.next;
        return bueno.next;

    }

};
