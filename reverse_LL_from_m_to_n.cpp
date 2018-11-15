using namespace std;
#include<cstdio>


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

     ListNode* rev(ListNode* cur, ListNode* prev, ListNode* head, ListNode* r_tail){
        if (cur->next == r_tail){
            head = cur;
            cur->next = prev;
            return head;
        }

        ListNode* next = cur->next;
        cur->next = prev;
        return rev(next, cur, head, r_tail);

    }



    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if(head->next == NULL) return head;
        if(m==n) return head;

        ListNode* n_head = head;
        ListNode* n_tail = head;

        for(int i=1;i<m;i++){
            n_head = n_head->next;
        }
        for(int i=1;i<n;i++){
            n_tail = n_tail->next;
        }
        ListNode* r_tail = n_tail->next;

        ListNode* temp = head;

        if(m==1) return rev(n_head, r_tail, n_head, r_tail);

        for(int i=1; i<m; i++){
             if(i == m -1 ){
                 temp->next = rev(n_head, r_tail, n_head, r_tail);
             }else{
                 temp = temp->next;
             }
        }

        return head;
    }

};
