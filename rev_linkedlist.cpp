#include <cstdio>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

    ListNode* rev(ListNode* cur, ListNode* prev, ListNode* head){
        if(cur->next == NULL){
            head = cur;
            cur->next = prev;
            return head;
        }

        ListNode* next = cur->next;
        cur->next = prev;
        return rev(next,cur,head);

    }


    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* l = rev (head, NULL, head);
        return l;

    }
};
