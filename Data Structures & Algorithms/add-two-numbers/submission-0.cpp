/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode;
        int carry = 0;
        ListNode* ret = sum;
        while(l1 || l2){
            int val;
            if(!l1){
                val = l2->val + carry;
                l2 = l2->next;
            }
            else if(!l2){
                val = l1->val + carry;
                l1 = l1->next;
            }
            else{
                val = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            carry = val / 10;
            val = val % 10;
            sum->val = val;
            if(!l1 && !l2){
                if(carry > 0){
                    ListNode* temp = new ListNode;
                    sum->next = temp;
                    sum = sum->next;
                    sum->val = carry;
                }
            }
            else{
                ListNode* temp = new ListNode;
                sum->next = temp;
                sum = sum->next;
            }
        }
        
        return ret;
    }
};
