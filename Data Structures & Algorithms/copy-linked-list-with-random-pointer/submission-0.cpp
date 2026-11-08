/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        unordered_map <Node*, Node*> mp;
        Node* head1 = new Node(head->val);
        Node* ret = head1;
        mp[head] = head1;
        while(head){
            if(head->next){
                if(mp.find(head->next) == mp.end()){
                    Node* temp = new Node(head->next->val);
                    head1->next = temp;
                    mp[head->next] = head1->next;
                }
                else{
                    head1->next = mp[head->next];
                }
            }
            if(head->random){
                if(mp.find(head->random) == mp.end()){
                    Node* temp = new Node(head->random->val);
                    head1->random = temp;
                    mp[head->random] = head1->random;
                }
                else{
                    head1->random = mp[head->random];
                }
            }
            head1 = head1->next;
            head = head->next;
        }
        return ret;
    }
};
