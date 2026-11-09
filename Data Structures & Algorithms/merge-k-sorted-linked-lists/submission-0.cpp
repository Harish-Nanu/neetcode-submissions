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

#define pii pair <int, ListNode*>

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <pii, vector <pii>, greater <pii>> pq;
        if(lists.empty()){
            return NULL;
        }
        for(auto &node : lists){
            if(node){
                pq.push(make_pair(node->val, node));
            }
        }
        if(pq.empty()){
            return NULL;            
        }
        ListNode* head = new ListNode;
        ListNode* ret = head;
        while(!pq.empty()){
            pii sh = pq.top();
            pq.pop();
            int curr_val = sh.first;
            ListNode* currNode = sh.second;
            head->val = curr_val;
            if(currNode->next){
                currNode = currNode->next;
                pq.push(make_pair(currNode->val, currNode));
            }
            if(!pq.empty()){
                ListNode* temp = new ListNode;
                head->next = temp;
                head = head->next;
            }
        }
        return ret;
    }
};
