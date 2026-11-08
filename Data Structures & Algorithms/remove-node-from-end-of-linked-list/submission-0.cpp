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

    void remove(ListNode* curr, ListNode* par, int n){
        if(n == 0){
            if(par){
                par->next = curr->next;
            }
        }
        else{
            remove(curr->next, curr, n-1);
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int pass = 0;
        while(temp){
            pass++;
            temp = temp->next;
        }
        n = pass - n;
        remove(head, NULL, n);
        if(!n){
            return head->next;
        }
        return head;
    }
};
