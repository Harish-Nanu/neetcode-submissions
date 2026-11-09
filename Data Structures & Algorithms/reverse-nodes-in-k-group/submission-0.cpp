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

    
    ListNode* ghead = NULL;
    ListNode* gtail = NULL;

    void rev(ListNode* head, ListNode* prev, ListNode* stop){
        if(head == stop){
            ghead = prev;
            return;
        }
        else{
            rev(head->next, head, stop);
        }
        head->next = prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        bool st = true;
        ListNode* gprev = NULL;
        ghead = head;
        ListNode* gnext = NULL;
        ListNode* ret;
        int rcnt = 0;
        while(head){
            cnt++;
            rcnt++;
            if(cnt == k){
                // cout << "call" << endl;
                gnext = head->next;
                gtail = ghead;
                // cout << ghead->val << " " << rcnt << " " << head->val << " " << gnext->val << " " << endl;
                rev(ghead, gnext, gnext);
                if(gprev){
                    gprev->next = ghead;
                }
                if(st){
                    st = false;
                    ret = ghead;
                }
                gprev = gtail;
                // cout << gtail->val << " " << gnext->val << endl;
                gtail->next = gnext;                
                head = gtail;
                gtail = NULL;
                ghead = gnext;
                cnt = 0;
                // cout << ghead->val << gtail->val << gprev->val
            }
            head = head->next;   
        }
        return ret;
    }
};
