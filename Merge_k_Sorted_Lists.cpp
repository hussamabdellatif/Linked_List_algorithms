// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

#include<cstdio>
#include<vector>
using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* l;
        ListNode* r;
        for(int i=0;i<lists.size();i++){
            if(!lists[i]){
                lists.erase(lists.begin()+i);
                i = i-1;
            }
            if(i>1) break;
        }
        if(!lists.size()) return NULL;
        if(lists.size() == 1) return lists[0];
        l = (lists[0]->val <= lists[1]->val) ? lists[0]:lists[1];
        r = (lists[0]->val  > lists[1]->val) ? lists[0]:lists[1];
        ListNode* new_head = rec(l, r, l);

        for(int i=2;i<lists.size();i++){
            if(!lists[i]) continue;
            l = (lists[i]->val <= new_head->val) ? lists[i]:new_head;
            r = (lists[i]->val  > new_head->val) ? lists[i]:new_head;
            if(l == r) return NULL;
            new_head = rec(l,r,l);
        }
        return new_head;

    }

    ListNode* rec(ListNode* l, ListNode* r, ListNode* head){
        if(!l || !r || !head) return head;
        if(l->next == NULL && r) {
            l->next = r;return head;}
        int temp_v = (!l->next) ?  0:l->next->val;
        if(l->val >= r->val || temp_v > r->val){
            ListNode* temp = l->next;
            l->next = r;
            r = temp;
        }
        return rec(l->next, r, head);



    }
};
