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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(!head){
            return false;
        }
        if(head == head->next){
            return true;
        }
        else if(!(head->next)){
            return false;
        }
        else{
            slow = head->next;
            fast = head->next->next;
        }
        while(slow){
            if((slow == fast) && (slow != NULL)){
                return true;
            }
            if(!fast || !(fast->next)){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
