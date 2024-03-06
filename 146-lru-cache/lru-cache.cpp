class LRUCache {
public:
    class Node {
    public:
        int key_;
        int val_;
        Node* next;
        Node* prev;
        Node(int key, int val) {
            key_ = key;
            val_ = val;
            next = NULL;
            prev = NULL;
        }
    };

    unordered_map<int, Node*> mp;
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void add(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        temp->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
    }

    void delet(Node* delnode) {
        Node* delnext = delnode->next;
        Node* delprev = delnode->prev;
        delprev->next = delnext;
        delnext->prev = delprev;

        //delete (delnode);
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            int val = node->val_;
            mp.erase(key);
            delet(node);
            Node* newnode = new Node(key,val);
            add(newnode);
            mp[key]=head->next;
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
                delet(mp[key]);
                mp.erase(key);
                Node* newnode = new Node(key, value);
                add(newnode);
                mp[key] = newnode;
            }
        else if (cap == 0) {
            Node* node = tail->prev;
            int keyy = node->key_;
            delet(node);
            mp.erase(keyy);
            Node* newnode = new Node(key, value);
            add(newnode);
            mp[key] = newnode;
        } else if (cap > 0) {
            if (mp.find(key) != mp.end()) {
                delet(mp[key]);
                mp.erase(key);
                Node* newnode = new Node(key, value);
                add(newnode);
                mp[key] = newnode;
            } else {
                
                Node* newnode = new Node(key, value);
                add(newnode);
                mp[key] = newnode;
                cap--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */