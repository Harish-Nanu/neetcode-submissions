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
    void reorderList(ListNode* head) {
        unordered_map <int, ListNode*> pos;
        int n = 0;
        ListNode* trav = head;
        while(trav){
            pos[n] = trav;
            n++;
            trav = trav->next;
        }
        pos[n] = NULL; pos[n+1] = NULL; pos[n+2] = NULL;
        trav = head;
        for(int i = 0; i < n/2; i++){
            pos[i]->next = pos[n-i-1];
        }
        for(int i = n-1; i > n/2; i--){
            pos[i]->next = pos[n-i];
        }
        pos[(n)/2]->next = NULL;
    }
};
