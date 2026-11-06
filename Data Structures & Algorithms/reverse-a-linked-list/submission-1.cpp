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
    bool fl = false;
    ListNode* ans = NULL;
    void Reverse(ListNode* curr, ListNode* par){
        if(!curr){
            return;
        }
        Reverse(curr->next, curr);
        if(!fl){
            fl = true;
            ans = curr;
        }
        curr->next = par;
    }

    ListNode* reverseList(ListNode* head) {
        Reverse(head, NULL);
        return ans;
    }
};
