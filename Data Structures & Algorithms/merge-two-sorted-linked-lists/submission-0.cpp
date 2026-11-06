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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* start = new ListNode;
        ListNode* ret = start;
        bool fi = true;
        if(!list1 && !list2){
            return NULL;
        }
        while(list1 || list2){
            bool ch = 0;
            if(!list1){
                ch = 1;
            }
            else if(!list2){
                ch = 0;
            }
            else if(list1->val < list2->val){
                ch = 0;
            }
            else{
                ch = 1;
            }
            if(ch){
                if(fi){
                    start->val = list2->val;
                    fi = false;
                }
                else{
                    ListNode* curr = new ListNode(list2->val);
                    start->next = curr;
                    start = start->next;
                }
                list2 = list2->next;
            }
            else{
                if(fi){
                    start->val = list1->val;
                    fi = false;
                }
                else{
                    ListNode* curr = new ListNode(list1->val);
                    start->next = curr;
                    start = start->next;
                }
                list1 = list1->next;
            }
        }   
        return ret;
    }
};
