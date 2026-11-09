class LRUCache {
public:

    struct Node{
        int val;
        Node* next = NULL;
        Node* prev = NULL;
    };

    int cap;
    int sz;
    Node* head = NULL;
    Node* tail = NULL;
    unordered_map <Node*, int> keys;
    unordered_map <int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        sz = 0;
    }
    
    void remove(Node* curr){
        Node* front = curr->next;
        Node* back = curr->prev;
        if(front){
            front->prev = back;
        }
        if(back){
            back->next = front;
        }
        if(head == tail){
            head = NULL;
            tail = NULL;
        }
        else if(curr == head){
            head = head->next;
        }
        else if(curr == tail){
            tail = tail->prev;
        }
        mp.erase(keys[curr]);
        keys.erase(curr);
    }

    void insert(int key, int value){
        Node* temp = new Node;
        temp->val = value;
        if(!head){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        mp[key] = temp;
        keys[temp] = key;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            remove(curr);
            insert(key, curr->val);
            return curr->val;
        }   
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            remove(curr);
        }   
        else{
            sz++;
        }
        insert(key, value);
        if(sz > cap){
            sz = cap;
            remove(head);
        }
    }
};
