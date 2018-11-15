#include<vector>
#include<cstdio>
#include<math.h>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:



    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL) return true;


        vector<int> vec;
        while(head != NULL){
            vec.push_back(head->val);
            head = head->next;
        }

        if(vec.size() % 2 != 0){
            int mid = ceil(vec.size() / 2);
            for(int i=0; i<vec.size();i++){
            if(i == mid) break;
            if(vec[i] != vec[vec.size()-i-1]) return false;
        }
        }

        for(int i=0; i<vec.size();i++){
            if(vec[i] != vec[vec.size()-i-1]) return false;
        }

        return true;
    }


};
